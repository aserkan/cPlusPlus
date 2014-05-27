#include "stdafx.h"

#include "Layer.h"
#include "Scene.h"
#include "VectorGraphic.h"
#include "TestHarness.h"


TEST(pushBack, Layer)
{
	VectorGraphics::Layer layer("Mountains");

	layer.pushBack(VectorGraphics::PlacedGraphic(VectorGraphics::Point(11, 11), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));
	layer.pushBack(VectorGraphics::PlacedGraphic(VectorGraphics::Point(22, 22), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));
	layer.pushBack(VectorGraphics::PlacedGraphic(VectorGraphics::Point(33, 33), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));

	int numberOfGraphics = 0;
	for (auto pos = layer.begin(); pos != layer.end(); ++pos)
	{
		++numberOfGraphics;
	}

	int expectedSize = 3;
	CHECK_EQUAL(expectedSize, numberOfGraphics);
}

TEST(getAlias, Layer)
{
	VectorGraphics::Layer layer("Sea");

	std::string expected("Sea");
	CHECK_EQUAL(expected, layer.getAlias());
}

TEST(remove, Layer)
{
	VectorGraphics::Layer layer("Air");

	layer.pushBack(VectorGraphics::PlacedGraphic(VectorGraphics::Point(11, 11), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));
	layer.pushBack(VectorGraphics::PlacedGraphic(VectorGraphics::Point(22, 22), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));
	layer.pushBack(VectorGraphics::PlacedGraphic(VectorGraphics::Point(33, 33), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));

	layer.remove(VectorGraphics::PlacedGraphic(VectorGraphics::Point(33, 33), VectorGraphics::HVectorGraphic(new VectorGraphics::VectorGraphic)));

	int numberOfGraphics = 0;
	for (auto pos = layer.begin(); pos != layer.end(); ++pos)
	{
		++numberOfGraphics;
	}

	int expectedSize = 2;
	CHECK_EQUAL(expectedSize, numberOfGraphics);
}
