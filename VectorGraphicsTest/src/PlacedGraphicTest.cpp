#include "stdafx.h"


#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "TestHarness.h"

TEST(ctor, PlacedGraphic)
{
	VectorGraphics::HVectorGraphic vg(new VectorGraphics::VectorGraphic);
	VectorGraphics::PlacedGraphic pg(VectorGraphics::Point(44, 55), vg);

	VectorGraphics::Point expected(44, 55);
	CHECK_EQUAL(expected, pg.getPlacementPoint());
	CHECK_EQUAL(vg.get(), &pg.getGraphic());
}

TEST(setPlacementPoint, PlacedGraphic)
{
	VectorGraphics::PlacedGraphic graphic;
	graphic.setPlacementPoint(VectorGraphics::Point(44, 55));

	VectorGraphics::Point expected(44, 55);
	CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(setGraphic, PlacedGraphic)
{
	VectorGraphics::PlacedGraphic pg;
	VectorGraphics::HVectorGraphic vg(new VectorGraphics::VectorGraphic);
	pg.setGraphic(vg);

	CHECK_EQUAL(vg.get(), &pg.getGraphic());
}
