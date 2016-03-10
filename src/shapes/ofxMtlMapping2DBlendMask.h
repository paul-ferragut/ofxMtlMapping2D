#pragma once

#include "ofxMtlMapping2DShape.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
class ofxMtlMapping2DBlendMask : public ofxMtlMapping2DShape {
	
    public:
        
		ofxMtlMapping2DBlendMask();
        ~ofxMtlMapping2DBlendMask();
        
    protected:
        virtual void createDefaultShape();
        virtual void render();

};
