#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(200);

	//cout << cam.getDistance() << endl;

	generateSpheres();
}

void ofApp::update() {
    
}

void ofApp::generateSpheres() {
    spherePositions.clear();
    for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += xStep) {
        for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += yStep) {
            float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
            ofVec3f pos(x, y, z);
            spherePositions.push_back(pos);
        }
    }
}

void ofApp::draw() {
    cam.begin();

	for (auto& pos : spherePositions) {
		ofSetColor(pos.x + ofGetWidth() / 2, pos.y + ofGetHeight() / 2, 0);
		ofDrawSphere(pos, 5);
	}
    if (sphereSelected) {
        ofSetColor(0, 0, 255);
        ofDrawSphere(selectedSphere.x, selectedSphere.y, selectedSphere.z, 5);
    }
    
    cam.end();

    ofSetColor(0); 
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString("Step (i,d,r): " + ofToString(xStep), 10, 40);
    ofDrawBitmapString("DistDiv (1,2,3): " + ofToString(distDiv), 10, 60);
    ofDrawBitmapString("Amplitud (8,9,0): " + ofToString(amplitud), 10, 80);
    if (sphereSelected) {
        ofDrawBitmapString("Selected Sphere: (" + ofToString(selectedSphere.x) + ", " +
            ofToString(selectedSphere.y) + ", " +
            ofToString(selectedSphere.z) + ")", 10, 100);
    }
}

void ofApp::keyPressed(int key) {
    if (key == 'i') {
		xStep++;
		yStep++;
	} else if(key == 'd'){
		xStep--;
		yStep--;
    }
    else if (key == 'r') {
        xStep = 20;
        yStep = 20;
    }
	else if (key == 'f') {
		ofToggleFullscreen();
	}
    xStep = ofClamp(xStep, 5, 100);
    yStep = ofClamp(yStep, 5, 100);

    if (key == '1') {
		distDiv += 1.0;
	} else if(key == '2'){
		distDiv -= 1.0;
    }
    else if (key == '3') {
        distDiv = 50;
    }
    distDiv = ofClamp(distDiv, 1.0, 100.0);

    if(key == '8'){
        amplitud += 10.0;
    }
    else if (key == '9') {
        amplitud -= 10.0;
    }
	else if (key == '0') {
	    amplitud = 150.0;
	}
    amplitud = ofClamp(amplitud, 10.0, 200.0);

    generateSpheres();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    ofVec3f rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd);

    sphereSelected = false;
    for (auto& pos : spherePositions) {
        ofVec3f intersectionPoint;
        if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, 5.0, intersectionPoint)) {
            selectedSphere = pos;
            sphereSelected = true;
            break;
        }
    }

}

void ofApp::convertMouseToRay(int mouseX, int mouseY, ofVec3f& rayStart, ofVec3f& rayEnd) {
    // Obtener matrices de proyección y modelo/vista de la cámara
    glm::mat4 modelview = cam.getModelViewMatrix();
    glm::mat4 projection = cam.getProjectionMatrix();
    ofRectangle viewport = ofGetCurrentViewport();

    // Convertir coordenadas del mouse a Normalized Device Coordinates (NDC)
    float x = 2.0f * (mouseX - viewport.x) / viewport.width - 1.0f;
    float y = 1.0f - 2.0f * (mouseY - viewport.y) / viewport.height;

    // Crear el rayo en NDC
    glm::vec4 rayStartNDC(x, y, -1.0f, 1.0f); // Near plane
    glm::vec4 rayEndNDC(x, y, 1.0f, 1.0f);   // Far plane

    // Convertir a coordenadas mundiales
    glm::vec4 rayStartWorld = glm::inverse(projection * modelview) * rayStartNDC;
    glm::vec4 rayEndWorld = glm::inverse(projection * modelview) * rayEndNDC;

    rayStartWorld /= rayStartWorld.w;
    rayEndWorld /= rayEndWorld.w;

    rayStart = ofVec3f(rayStartWorld);
    rayEnd = ofVec3f(rayEndWorld);
}

//--------------------------------------------------------------
// Detectar si el rayo intersecta una esfera
bool ofApp::rayIntersectsSphere(const ofVec3f& rayStart, const ofVec3f& rayDir, const ofVec3f& sphereCenter, float sphereRadius, ofVec3f& intersectionPoint) {
    ofVec3f oc = rayStart - sphereCenter;

    float a = rayDir.dot(rayDir); 
    float b = 2.0f * oc.dot(rayDir);
    float c = oc.dot(oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    else {
        float t = (-b - sqrt(discriminant)) / (2.0f * a);
        intersectionPoint = rayStart + t * rayDir;
        return true;
    }
}
