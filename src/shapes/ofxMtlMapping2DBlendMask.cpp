#include "ofxMtlMapping2DBlendMask.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
ofxMtlMapping2DBlendMask::ofxMtlMapping2DBlendMask()
{

	/*
	string vertShaderSrc = STRINGIFY(
		//#version 120
		//attribute vec4 position;
		varying vec4 globalColor;

		//varying vec2 v_texcoord0;
		void main(void)
	{
	//	gl_Position = modelViewProjectionMatrix * position;
	//	gl_Position = ftransform();
		//v_texcoord0 = a_texcoord0;

		gl_TexCoord[0] = gl_MultiTexCoord0;

		//get our current vertex position so we can modify it
		vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
		gl_Position = pos;

		// in OpenGL 2.0 we must get the global color using the gl_Color command,
		// and store it in a globalColor (varying) that is passed to our frag shader.
		// please note that the frag shader also has a globalColor (varying),
		// and this is the standard way of passing data from the vertex shader to the frag shader.
		globalColor = gl_Color;
	}
	);

	string fragShaderSrc = STRINGIFY(
		//#version 120

	uniform vec2 tr;
	uniform vec2 tl;
	uniform vec2 br;
	uniform vec2 bl;


	float distanceToLineSeg(vec2 p, vec2 a, vec2 b)
	{
		//e = capped [0,1] orthogonal projection of ap on ab
		//       p
		//      /
		//     /
		//    a--e-------b
		vec2 ap = p - a;
		vec2 ab = b - a;
		vec2 e = a + clamp(dot(ap, ab) / dot(ab, ab), 0.0, 1.0)*ab;
		return length(p - e);
	}

		void main(void)
	{




		float a = (gl_FragCoord.x  / distanceToLineSeg(gl_FragCoord, tl, br))*(gl_FragCoord.x / distanceToLineSeg(gl_FragCoord, tr, bl));//
		gl_FragColor = vec4(0.0,0.0,0.0, a);
	}
	);
	shaderBlend.setupShaderFromSource(GL_VERTEX_SHADER, vertShaderSrc);
	shaderBlend.setupShaderFromSource(GL_FRAGMENT_SHADER, fragShaderSrc);
	shaderBlend.linkProgram();

	*/
	meshBlend.addVertex(ofVec3f(0, 0));
	meshBlend.addColor(ofColor(0, 0, 0, 255));

	meshBlend.addVertex(ofVec3f(0,0));
	meshBlend.addColor(ofColor(0, 0, 0, 0));

	meshBlend.addVertex(ofVec3f(0, 0));
	meshBlend.addColor(ofColor(0, 0, 0, 0));

	meshBlend.addVertex(ofVec3f(0, 0));
	meshBlend.addColor(ofColor(0, 0, 0, 255));

	meshBlend.addTriangle(0, 1, 3);
	meshBlend.addTriangle(3, 2, 1);

}

//--------------------------------------------------------------
ofxMtlMapping2DBlendMask::~ofxMtlMapping2DBlendMask(){

}

//--------------------------------------------------------------
void ofxMtlMapping2DBlendMask::render()
{

	if(meshBlend.getNumVertices()== polyline->size())  {
    for (int i = 0; i < polyline->size(); i++) {
		
		 meshBlend.setVertex(i,ofVec3f(polyline->getVertices()[i].x, polyline->getVertices()[i].y));
    }
	meshBlend.draw();
	}

}

//--------------------------------------------------------------
void ofxMtlMapping2DBlendMask::createDefaultShape()
{
    shapeSettings["type"] = "blendMask";


	int xOffset = ofGetWidth() / 2.0;
	int yOffset = ofGetHeight() / 2.0;

	//Create a new vertex
	int x = 0;
	int y = 0;

	ofxMtlMapping2DVertex* newVertex = new ofxMtlMapping2DVertex();
	newVertex->init(xOffset + x - newVertex->width / 2, yOffset + y - newVertex->height / 2);
	vertices.push_back(newVertex);
	meshBlend.addVertex(ofVec3f(x, y));
	meshBlend.addColor(ofColor(0,0,0,255));

	//Create a new vertex
	x = 0;
	y = 100;

	newVertex = new ofxMtlMapping2DVertex();
	newVertex->init(xOffset + x - newVertex->width / 2, yOffset + y - newVertex->height / 2);
	vertices.push_back(newVertex);
	meshBlend.addVertex(ofVec3f(x, y));
	meshBlend.addColor(ofColor(0, 0, 0, 0));

	//Create a new vertex
	x = 100;
	y = 100;

	newVertex = new ofxMtlMapping2DVertex();
	newVertex->init(xOffset + x - newVertex->width / 2, yOffset + y - newVertex->height / 2);
	vertices.push_back(newVertex);
	meshBlend.addVertex(ofVec3f(x, y));
	meshBlend.addColor(ofColor(0, 0, 0, 0));
	//Create a new vertex
	x = 100;
	y = 0;

	newVertex = new ofxMtlMapping2DVertex();
	newVertex->init(xOffset + x - newVertex->width / 2, yOffset + y - newVertex->height / 2);
	vertices.push_back(newVertex);
	meshBlend.addVertex(ofVec3f(x, y));
	meshBlend.addColor(ofColor(0, 0, 0, 255));

	meshBlend.addTriangle(0, 1, 3);
	meshBlend.addTriangle(3, 2, 1);
}

//--------------------------------------------------------------
/*
void ofxMtlMapping2DBlendMask::calcHomography()
{
	updatePolyline();

	inputPolygon->calcHomography(polyline->getVertices()[0].x, polyline->getVertices()[0].y,
		polyline->getVertices()[1].x, polyline->getVertices()[1].y,
		polyline->getVertices()[2].x, polyline->getVertices()[2].y,
		polyline->getVertices()[3].x, polyline->getVertices()[3].y);
}

*/