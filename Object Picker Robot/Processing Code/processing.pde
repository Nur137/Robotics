import processing.video.*;

import processing.serial.*;

Serial myPort;  // Create object from Serial class
String portName;
Capture video;

color trackColorgreen,trackColorblue,trackColoryellow; 
float threshold = 20;
float distThreshold = 75;

ArrayList<Blob> blobgreen = new ArrayList<Blob>();
ArrayList<Blob> blobblue = new ArrayList<Blob>();
ArrayList<Blob> blobyellow = new ArrayList<Blob>();


void findcolorgreen()
{
for (int x = 0; x < video.width; x++ ) {
    for (int y = 0; y < video.height; y++ ) {
      int loc = x + y * video.width;
      // What is current color
      color currentColor = video.pixels[loc];
      float r1 = red(currentColor);
      float g1 = green(currentColor);
      float b1 = blue(currentColor);
      float r2 = red(trackColorgreen);
      float g2 = green(trackColorgreen);
      float b2 = blue(trackColorgreen);

      float d = distSq(r1, g1, b1, r2, g2, b2); 

      if (d < threshold*threshold) {

        boolean found = false;
        for (Blob b : blobgreen) {
          if (b.isNear(x, y)) {
            b.add(x, y);
            found = true;
            break;
          }
        }
   
        if (!found) {
          Blob b = new Blob(x, y);
          blobgreen.add(b);
         }
      }
    }
  }

}


void findcolorblue()
{
for (int x = 0; x < video.width; x++ ) {
    for (int y = 0; y < video.height; y++ ) {
      int loc = x + y * video.width;
      // What is current color
      color currentColor = video.pixels[loc];
      float r1 = red(currentColor);
      float g1 = green(currentColor);
      float b1 = blue(currentColor);
      float r2 = red(trackColorblue);
      float g2 = green(trackColorblue);
      float b2 = blue(trackColorblue);

      float d = distSq(r1, g1, b1, r2, g2, b2); 

      if (d < threshold*threshold) {

        boolean found = false;
        for (Blob b : blobblue) {
          if (b.isNear(x, y)) {
            b.add(x, y);
            found = true;
            break;
          }
        }
   
        if (!found) {
          Blob b = new Blob(x, y);
          blobblue.add(b);
         }
      }
    }
  }


}


void findcoloryellow()
{

for (int x = 0; x < video.width; x++ ) {
    for (int y = 0; y < video.height; y++ ) {
      int loc = x + y * video.width;
      // What is current color
      color currentColor = video.pixels[loc];
      float r1 = red(currentColor);
      float g1 = green(currentColor);
      float b1 = blue(currentColor);
      float r2 = red(trackColoryellow);
      float g2 = green(trackColoryellow);
      float b2 = blue(trackColoryellow);

      float d = distSq(r1, g1, b1, r2, g2, b2); 

      if (d < threshold*threshold) {

        boolean found = false;
        for (Blob b : blobyellow) {
          if (b.isNear(x, y)) {
            b.add(x, y);
            found = true;
            break;
          }
        }
   
        if (!found) {
          Blob b = new Blob(x, y);
          blobyellow.add(b);
         }
      }
    }
  }

}

void setup() {
  size(640, 360);
  String[] cameras = Capture.list();
  printArray(cameras);
  video = new Capture(this, cameras[3]);
  video.start();
  //trackColorgreen = color(11,77,28);
  trackColorgreen = color(46,181,102);
  //trackColorblue = color( 22,135,217);
  trackColorblue = color( 0,110,255);
  //trackColoryellow = color(179,136,9);
  trackColoryellow = color(221,228,125);
   portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);

}

void captureEvent(Capture video) {
  video.read();
}



void draw() {
  video.loadPixels();
  image(video, 0, 0);

  blobgreen.clear();

  blobyellow.clear();

  blobblue.clear();

  //threshold = map(mouseX, 0, width, 0, 100);
  threshold = 80;

  // Begin loop to walk through every pixel
  findcolorgreen();
  findcolorblue();
  findcoloryellow();
  
  if(blobgreen.size()==0 && blobblue.size()==0 && blobyellow.size()==0)myPort.write('0');


  for (Blob b : blobblue) {
    if (b.size() > 800) {
      b.show();
      myPort.write('1');
      println("blue");
    }
  }
  
  
  for (Blob b : blobgreen) {
    if (b.size() > 800) {
      b.show();
      myPort.write('2');
      println("green");
    }
  }

  for (Blob b : blobyellow) {
    if (b.size() > 800) {
      b.show();
      myPort.write('3');
      println("yellow");
    }
  }

}


float distSq(float x1, float y1, float x2, float y2) {
  float d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  return d;
}


float distSq(float x1, float y1, float z1, float x2, float y2, float z2) {
  float d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) +(z2-z1)*(z2-z1);
  return d;
}

void mousePressed() {
  // Save color where the mouse is clicked in trackColor variable
  int loc = mouseX + mouseY*video.width;
  color trackColor = video.pixels[loc];
 
}



class Blob {
  float minx;
  float miny;
  float maxx;
  float maxy;

  Blob(float x, float y) {
    minx = x;
    miny = y;
    maxx = x;
    maxy = y;
  }

  void show() {
    stroke(0);
    fill(255);
    strokeWeight(2);
    rectMode(CORNERS);
    rect(minx, miny, maxx, maxy);
  }

  void add(float x, float y) {
    minx = min(minx, x);
    miny = min(miny, y);
    maxx = max(maxx, x);
    maxy = max(maxy, y);
  }
  
  float size() {
    return (maxx-minx)*(maxy-miny); 
  }

  boolean isNear(float x, float y) {
    float cx = (minx + maxx) / 2;
    float cy = (miny + maxy) / 2;

    float d = distSq(cx, cy, x, y);
    if (d < distThreshold*distThreshold) {
      return true;
    } else {
      return false;
    }
  }
}