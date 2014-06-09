#include "stdafx.h"

//#include "XmlReader.h"
//#include "XmlTag.h"
//#include "Element.h"
#include "Scene.h"
#include "SceneStreamer.h"
#include "CodecLibrary.h"
#include "BasicCanvas.h"
#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "TestHarness.h"

#define STR(a) #a

const char* const TestXml = STR(
	<Scene width = "800" height = "600">
	<Layer alias = "sky">
	<PlacedGraphic x = "0" y = "0">
	<VectorGraphic closed = "true">
	<Point x = "1" y = "2" / >
	<!--Comment-->
	<Point x = "3" y = "4" / >
	<Point x = "5" y = "6" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	<!--Comment-->
	<PlacedGraphic x = "700" y = "0">
	<VectorGraphic closed = "false">
	<Point x = "7" y = "8" / >
	<Point x = "9" y = "10" / >
	<Point x = "11" y = "12" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	< / Layer>
	<Layer alias = "mountains">
	<PlacedGraphic x = "250" y = "250">
	<VectorGraphic closed = "false">
	<Point x = "13" y = "14" / >
	<Point x = "15" y = "19" / >
	<Point x = "17" y = "18" / >
	<!--etc... -->
	< / VectorGraphic>
	< / PlacedGraphic>
	< / Layer>
	< / Scene>);

const char* const TestXmlNoComment = STR(
	<Scene width = "800" height = "600">
	<Layer alias = "sky">
	<PlacedGraphic x = "0" y = "0">
	<VectorGraphic closed = "true">
	<Point x = "1" y = "2" / >
	<Point x = "3" y = "4" / >
	<Point x = "5" y = "6" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	<PlacedGraphic x = "700" y = "0">
	<VectorGraphic closed = "false">
	<Point x = "7" y = "8" / >
	<Point x = "9" y = "10" / >
	<Point x = "11" y = "12" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	< / Layer>
	<Layer alias = "mountains">
	<PlacedGraphic x = "250" y = "250">
	<VectorGraphic closed = "false">
	<Point x = "13" y = "14" / >
	<Point x = "15" y = "19" / >
	<Point x = "17" y = "18" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	< / Layer>
	< / Scene>);

const char* const sceneXml = STR(
	<Scene width = "800" height = "800">
	<Layer alias = "bottom">
	<PlacedGraphic x = "0" y = "0">
	<VectorGraphic closed = "true">
	<Stroke tip = "slash" size = "7" color = "FF0000" / >
	<Point x = "100" y = "500" / >
	<Point x = "100" y = "100" / >
	<Point x = "500" y = "600" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	<PlacedGraphic x = "400" y = "300">
	<VectorGraphic closed = "true">
	<Stroke tip = "square" size = "5" color = "00FF00" / >
	<Point x = "0" y = "0" / >
	<Point x = "0" y = "100" / >
	<Point x = "100" y = "100" / >
	<Point x = "100" y = "0" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	< / Layer>
	<Layer alias = "top">
	<PlacedGraphic x = "250" y = "250">
	<VectorGraphic closed = "false">
	<Stroke tip = "square" size = "3" color = "0000FF" / >
	<Point x = "0" y = "0" / >
	<Point x = "0" y = "100" / >
	<Point x = "100" y = "100" / >
	<Point x = "100" y = "0" / >
	< / VectorGraphic>
	< / PlacedGraphic>
	< / Layer>
	< / Scene>);


using namespace BitmapGraphics;

TEST(BasicCanvasReadScene, SceneReader)
{
	std::stringstream xmlStream(TestXmlNoComment);
	//Xml::HElement root = Xml::Reader::loadXml(xmlStream);
	//Node root = Streamer::fromXml(xmlStream);

	//VectorGraphics::Scene s = VectorGraphics::SceneReader::readScene(*root);
	VectorGraphics::Scene s = VectorGraphics::SceneStreamer::fromXml(xmlStream);

	CHECK_EQUAL(800, s.getWidth());
	CHECK_EQUAL(600, s.getHeight());

	VectorGraphics::Scene::LayerIterator pos;
	int iLayer;
	for (iLayer = 0, pos = s.begin(); pos != s.end(); ++iLayer, ++pos)
	{
		const VectorGraphics::Layer& layer = (*pos);
		if (iLayer == 0)
		{
			// verify sky layer
			CHECK_EQUAL("sky", layer.getAlias());
			VectorGraphics::Layer::const_PlacedGraphicIterator graphic;
			int iGraphic;
			for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
			{
				if (iGraphic == 0)
				{
					CHECK_EQUAL(VectorGraphics::Point(0, 0), (*graphic).getPlacementPoint());
					const VectorGraphics::VectorGraphic& vg = (*graphic).getGraphic();
					CHECK_EQUAL(true, vg.isClosed());
					CHECK_EQUAL(3, vg.getPointCount());
					CHECK_EQUAL(VectorGraphics::Point(1, 2), vg.getPoint(0));
					CHECK_EQUAL(VectorGraphics::Point(3, 4), vg.getPoint(1));
					CHECK_EQUAL(VectorGraphics::Point(5, 6), vg.getPoint(2));

				}
				else if (iGraphic == 1)
				{
					CHECK_EQUAL(VectorGraphics::Point(700, 0), (*graphic).getPlacementPoint());
					const VectorGraphics::VectorGraphic& vg = (*graphic).getGraphic();
					CHECK_EQUAL(false, vg.isClosed());
				}
			}

			CHECK_EQUAL(2, iGraphic);
		}
		else if (iLayer == 1)
		{
			// verify mountains layer
			CHECK_EQUAL("mountains", layer.getAlias());

			VectorGraphics::Layer::const_PlacedGraphicIterator graphic;
			int iGraphic;
			for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
			{
			}

			CHECK_EQUAL(1, iGraphic);
		}
	}

	// Expect 2 layers
	CHECK_EQUAL(2, iLayer);
}

//////////////////
//using namespace BitmapGraphics;
namespace
{
	class CodecLibrarySetup
	{
	public:
		CodecLibrarySetup()
		{
			myCodecLibrary.registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
			myCodecLibrary.registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));
		}

		operator CodecLibrary&()
		{
			return myCodecLibrary;
		}

	private:
		BitmapGraphics::CodecLibrary myCodecLibrary;

	};
}

TEST(toBitmap, SceneReader)
{
	std::stringstream xmlStream(sceneXml);

	// Parse the XML into a DOM
	//Xml::HElement root = Xml::Reader::loadXml(xmlStream);

	// Construct a vector graphic Scene from the DOM
	VectorGraphics::Scene scene = VectorGraphics::SceneStreamer::fromXml(xmlStream);

	// Create an empty Canvas
	Color backgroundColor(100, 100, 100);
	HCanvas canvas(new BitmapGraphics::BasicCanvas(scene.getWidth(), scene.getHeight(), backgroundColor));
	
	// Draw the Scene onto the Canvas
	scene.draw(canvas);
	
	// Create a WindowsBitmapFileProjector and give it an output file name to create
	// Also give it the CodecLibrary ("dependency injection").
	CodecLibrarySetup codecLibrary;
	HProjector projector(new WindowsBitmapFileProjector("output_scene.bmp", codecLibrary));

	// Project the Canvas into the bitmap file
	projector->projectCanvas(canvas);
}