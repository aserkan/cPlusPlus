#include "stdafx.h"

#include "Scene.h"
#include "SceneStreamer.h"
#include "TestHarness.h"

#define STR(a) #a

const char* const TestXml = STR(
	<Scene width = "800" height = "600">
	<Layer alias = "sky">
	<PlacedGraphic x = "86" y = "99">
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
	<!-- - etc. ---------->
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


const char* const TestXmlNoComment = STR(
	<Scene width = "800" height = "600">
	<Layer alias = "sky">
	<PlacedGraphic x = "86" y = "99">
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

TEST(WriteScene, SceneWriter)
{
	//std::stringstream xmlStream(TestXml);
	std::stringstream xmlStream(TestXmlNoComment);

	VectorGraphics::Scene scene = VectorGraphics::SceneStreamer::fromXml(xmlStream);

	// Go back the other way and construct another DOM from the Scene
	std::stringstream outputXml;
	VectorGraphics::SceneStreamer::toXml(scene, outputXml);
	Node root = VectorGraphics::SceneStreamer::toNode(scene);

	// Now verify some things in the new DOM...
	CHECK_EQUAL("Scene", root.getName());
	//Xml::AttributeMap attributes = root->getAttributes();
	CHECK_EQUAL(2, root.getAttributes().size());
	CHECK_EQUAL("800", root.getAttributes()["width"]);
	CHECK_EQUAL("600", root.getAttributes()["height"]);

	std::vector<Node> sceneChildren = root.getChildren();
	CHECK_EQUAL(2, sceneChildren.size());
	Node layer0 = sceneChildren[0];

	CHECK_EQUAL("Layer", layer0.getName());
	CHECK_EQUAL(1, layer0.getAttributes().size());
	CHECK_EQUAL("sky", layer0.getAttributes()["alias"]);

	std::vector<Node> layerChildren = layer0.getChildren();
	CHECK_EQUAL(2, layerChildren.size());

	CHECK_EQUAL(2, layerChildren.size());
	Node placedGraphic0 = layerChildren[0];
	CHECK_EQUAL("86", placedGraphic0.getAttributes()["x"]);
	CHECK_EQUAL("99", placedGraphic0.getAttributes()["y"]);

	std::vector<Node> placedGraphicChildren = placedGraphic0.getChildren();
	CHECK_EQUAL(1, placedGraphicChildren.size());
	Node vectorGraphic0 = placedGraphicChildren[0];
	CHECK_EQUAL(1, vectorGraphic0.getAttributes().size());
	CHECK_EQUAL("true", vectorGraphic0.getAttributes()["closed"]);

	std::vector<Node> vectorGraphicChildren = vectorGraphic0.getChildren();
	CHECK_EQUAL(3, vectorGraphicChildren.size());
	CHECK_EQUAL("Point", vectorGraphicChildren[0].getName());
	CHECK_EQUAL("1", vectorGraphicChildren[0].getAttributes()["x"]);
	CHECK_EQUAL("2", vectorGraphicChildren[0].getAttributes()["y"]);

	CHECK_EQUAL("Point", vectorGraphicChildren[1].getName());
	CHECK_EQUAL("3", vectorGraphicChildren[1].getAttributes()["x"]);
	CHECK_EQUAL("4", vectorGraphicChildren[1].getAttributes()["y"]);

	CHECK_EQUAL("Point", vectorGraphicChildren[2].getName());
	CHECK_EQUAL("5", vectorGraphicChildren[2].getAttributes()["x"]);
	CHECK_EQUAL("6", vectorGraphicChildren[2].getAttributes()["y"]);

}