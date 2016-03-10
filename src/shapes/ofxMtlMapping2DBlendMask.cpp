#include "ofxMtlMapping2DBlendMask.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
ofxMtlMapping2DBlendMask::ofxMtlMapping2DBlendMask()
{

}

//--------------------------------------------------------------
ofxMtlMapping2DBlendMask::~ofxMtlMapping2DBlendMask(){

}

//--------------------------------------------------------------
void ofxMtlMapping2DBlendMask::render()
{
    ofBeginShape();
    ofFill();    
    for (int i = 0; i < polyline->size(); i++) {
        ofVertex(polyline->getVertices()[i].x, polyline->getVertices()[i].y);
    }
    ofEndShape(true);
}

//--------------------------------------------------------------
void ofxMtlMapping2DBlendMask::createDefaultShape()
{
    shapeSettings["type"] = "blendMask";
    
    int xOffset = ofGetWidth()/2.0;
    int yOffset = ofGetHeight()/2.0;

    //Create a new vertex
    int x = 50;
    int y = 0;
    
    ofxMtlMapping2DVertex* newVertex = new ofxMtlMapping2DVertex();
    newVertex->init(xOffset + x - newVertex->width/2, yOffset + y - newVertex->height/2);
    vertices.push_back(newVertex);
    
    //Create a new vertex
    x = 0;
    y = 100;
    
    newVertex = new ofxMtlMapping2DVertex();
    newVertex->init(xOffset + x - newVertex->width/2, yOffset + y - newVertex->height/2);
    vertices.push_back(newVertex);
    
    //Create a new vertex
    x = 100;
    y = 100;
    
    newVertex = new ofxMtlMapping2DVertex();
    newVertex->init(xOffset + x - newVertex->width/2, yOffset + y - newVertex->height/2);
    vertices.push_back(newVertex);


	//Create a new vertex
	x = 100;
	y = 0;

	newVertex = new ofxMtlMapping2DVertex();
	newVertex->init(xOffset + x - newVertex->width / 2, yOffset + y - newVertex->height / 2);
	vertices.push_back(newVertex);
}