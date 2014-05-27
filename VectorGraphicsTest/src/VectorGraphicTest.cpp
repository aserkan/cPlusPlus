#include "stdafx.h"

#include "Parser.h"
#include "Streamer.h"
#include "VectorGraphic.h"
#include "VectorGraphicStreamer.h"
#include "TestHarness.h"

TEST(ctor, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	CHECK_EQUAL(0, VectorGraphics.getPointCount());
	CHECK_EQUAL(true, VectorGraphics.isClosed());
	CHECK_EQUAL(false, VectorGraphics.isOpen());
}

TEST(insertPoint, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	VectorGraphics.addPoint(VectorGraphics::Point(1, 1));
	CHECK_EQUAL(1, VectorGraphics.getPointCount());

	VectorGraphics.addPoint(VectorGraphics::Point(2, 2));
	CHECK_EQUAL(2, VectorGraphics.getPointCount());
}

TEST(removePoint, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	VectorGraphics.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics.removePoint(VectorGraphics::Point(1, 1));

	CHECK_EQUAL(1, VectorGraphics.getPointCount());
	CHECK_EQUAL(VectorGraphics::Point(2, 2), VectorGraphics.getPoint(0));
}

TEST(erasePoint, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	VectorGraphics.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics.addPoint(VectorGraphics::Point(3, 3));
	VectorGraphics.erasePoint(1);

	CHECK_EQUAL(2, VectorGraphics.getPointCount());
	CHECK_EQUAL(VectorGraphics::Point(1, 1), VectorGraphics.getPoint(0));
	CHECK_EQUAL(VectorGraphics::Point(3, 3), VectorGraphics.getPoint(1));
}

TEST(erasePointOutOfRange, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	VectorGraphics.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics.addPoint(VectorGraphics::Point(3, 3));

	try
	{
		VectorGraphics.erasePoint(5);
	}
	catch (std::out_of_range&)
	{
		CHECK_EQUAL(3, VectorGraphics.getPointCount());
		return;
	}
	CHECK(false); // should have caught exception
}

TEST(equality, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics1;
	VectorGraphics1.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics1.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics1.addPoint(VectorGraphics::Point(3, 3));

	VectorGraphics::VectorGraphic VectorGraphics2;
	VectorGraphics2.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics2.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics2.addPoint(VectorGraphics::Point(3, 3));

	CHECK(VectorGraphics1 == VectorGraphics2);
}

TEST(inequality, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics1;
	VectorGraphics1.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics1.addPoint(VectorGraphics::Point(1, 2));
	VectorGraphics1.addPoint(VectorGraphics::Point(1, 3));

	VectorGraphics::VectorGraphic VectorGraphics2;
	VectorGraphics2.addPoint(VectorGraphics::Point(2, 1));
	VectorGraphics2.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics2.addPoint(VectorGraphics::Point(2, 3));

	CHECK(VectorGraphics1 != VectorGraphics2);

	VectorGraphics::VectorGraphic VectorGraphics3;
	VectorGraphics3.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics3.addPoint(VectorGraphics::Point(1, 2));
	VectorGraphics3.addPoint(VectorGraphics::Point(1, 3));
	VectorGraphics3.openShape();

	CHECK(VectorGraphics3 != VectorGraphics1);
}

TEST(closeShape, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	VectorGraphics.closeShape();
	CHECK_EQUAL(true, VectorGraphics.isClosed());
	CHECK_EQUAL(false, VectorGraphics.isOpen());
}

TEST(openShape, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics;
	VectorGraphics.openShape();
	CHECK_EQUAL(false, VectorGraphics.isClosed());
	CHECK_EQUAL(true, VectorGraphics.isOpen());
}

TEST(widthHeight, VectorGraphic)
{
	VectorGraphics::VectorGraphic vectorGraphic;
	vectorGraphic.addPoint(VectorGraphics::Point(0, 2));
	vectorGraphic.addPoint(VectorGraphics::Point(4, 3));
	vectorGraphic.addPoint(VectorGraphics::Point(5, 8));
	vectorGraphic.addPoint(VectorGraphics::Point(2, 1));
	CHECK_EQUAL(5, vectorGraphic.getWidth());
	CHECK_EQUAL(7, vectorGraphic.getHeight());

	vectorGraphic.erasePoint(2);
	CHECK_EQUAL(4, vectorGraphic.getWidth());
	CHECK_EQUAL(2, vectorGraphic.getHeight());
}

#define STR(a) #a

const std::string VectorGraphicXml = STR(
	<VectorGraphic closed = "true">
	<Point x = "0" y = "0" / >
	<Point x = "10" y = "0">
	< / Point>
	<Point x = "10" y = "10" / >
	<Point x = "0" y = "10" / >
	< / VectorGraphic>);

TEST(fromXml, Streamer)
{
	std::stringstream sstr(VectorGraphicXml);

	Node root = Streamer::fromXml(sstr);

	CHECK_EQUAL(true, root.isClosing());
	CHECK_EQUAL("VectorGraphic", root.getName());
	CHECK_EQUAL(1, (root.getAttributes()).size());
	CHECK_EQUAL("true", (root.getAttributes())["closed"]);

	CHECK_EQUAL(4, (root.getChildren()).size());
	CHECK_EQUAL("Point", root.getChildren()[0].getName());
	CHECK_EQUAL(0, root.getChildren()[0].getChildren().size());
}

TEST(fromXml, VectorGraphic)
{
	std::stringstream sstr(VectorGraphicXml);

	VectorGraphics::VectorGraphic VectorGraphics = VectorGraphics::VectorGraphicStreamer::fromXml(sstr);

	CHECK_EQUAL(true, VectorGraphics.isClosed());
	CHECK_EQUAL(4, VectorGraphics.getPointCount());
	CHECK_EQUAL(10, VectorGraphics.getPoint(2).getX());
	CHECK_EQUAL(10, VectorGraphics.getPoint(2).getY());
}

#include <iostream>
TEST(toXml, VectorGraphic)
{
	VectorGraphics::VectorGraphic VectorGraphics1;
	VectorGraphics1.addPoint(VectorGraphics::Point(1, 1));
	VectorGraphics1.addPoint(VectorGraphics::Point(2, 2));
	VectorGraphics1.addPoint(VectorGraphics::Point(3, 3));

	std::stringstream sstr;
	VectorGraphics::VectorGraphicStreamer::toXml(VectorGraphics1, sstr);
	//std::cout << sstr.str() << std::endl;
	VectorGraphics::VectorGraphic VectorGraphics2 = VectorGraphics::VectorGraphicStreamer::fromXml(sstr);
	CHECK(VectorGraphics1 == VectorGraphics2);
}
