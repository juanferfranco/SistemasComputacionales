#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		
		void convertMouseToRay(int mouseX, int mouseY, ofVec3f& rayStart, ofVec3f& rayEnd);
		bool rayIntersectsSphere(const ofVec3f& rayStart, const ofVec3f& rayDir, const ofVec3f& sphereCenter, float sphereRadius, ofVec3f& intersectionPoint);
		void ofApp::generateSpheres();

		ofEasyCam cam;
		int xStep = 20;
		int yStep = 20;
		float distDiv = 50.0;
		float amplitud = 150.0;

		vector<ofVec3f> spherePositions;
		ofVec3f selectedSphere;
		bool sphereSelected = false;

};
