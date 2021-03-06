/**
 *  ofxNetworkedParameters
 *	
 *   Copyright (c) 2011, Tim Gfrerer, James George
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------
 *
 * ofxNetworkedParameters provides an easy way to share settings
 * between instances of the same application running on multiple machines
 * synchronized with Most Pixels Ever.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxMostPixelsEver.h"
#include "ofxNetworkedParameter.h"

#ifdef USE_NETWORKEDSIMPLEGUITOO
#include "ofxSimpleGuiToo.h"
#endif

class ofxNetworkedParametersHandler {
  public:
	ofxNetworkedParametersHandler();
	~ofxNetworkedParametersHandler();

	void setMPEClient(mpeClientTCP* client);

	void addNetworkedParameter(string _name, int * _p);
	void addNetworkedParameter(string _name, float * _p);
	void addNetworkedParameter(string _name, bool * _p);

    void attachToNetwork();
	void detachFromNetwork();

  private:
	void update(ofEventArgs& args);
	map<string, ofxNetworkedParameter *> parameterList;
	void mpeMessageEvent(ofxMPEEventArgs& eventArgs);
	mpeClientTCP* client;

};

// declare an external networkedParameters object, similar to ofxSimpleGuiToo
extern ofxNetworkedParametersHandler ofxNetworkedParameters;

