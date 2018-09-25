/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Filter.h"
#include "Sharpen.h"
#include "Kernel.h"
#include "Simple.h"
#include "PixelF.h"
#include "Image.h"
#include "Pixel.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <vector>
#include "Blur.h"
#include "Vflip.h"
#include "Hflip.h"
#include "Grayscale.h"
#include "Sepia.h"
#include "Binary.h"

int main(int argc, char const* argv[]){
  // makes sure there is the proper input and outputs
  if (argc != 2){
    std::cerr << "USAGE: ./out <in.ppm>" << endl;
    return 1;
  }


  //This creates seperate string names for each filter
  //string userFile = argv[2];
  string ppm1 = "sharpen_100.ppm";
  string ppm2 = "blur_100.ppm";
  string ppm3 = "horizontal_100.ppm";
  string ppm4 = "vertical_100.ppm";
  string ppm5 = "binary_100.ppm";
  string ppm6 = "sepia_100_ec.ppm";
  string ppm7 = "grayscale_100.ppm";


  //these are the strings for the combo filters
  string ppm8 = "shar_bin_hf_100.ppm";
  string ppm9 = "shar_sep_vf_100.ppm";
  string ppm10 = "shar_gs_hf_100.ppm";
  string ppm11 = "blur_gs_vf_100.ppm";
  string ppm12 = "blur_bin_hf_100.ppm";
  string ppm13 = "blur_sep_vf_100.ppm";
  string ppm14 = "stud_creation_100.ppm";

  // the input and output files
  std::ifstream input(argv[1]);
  std::ofstream output(ppm1);
  std::ofstream output2(ppm2);
  std::ofstream output3(ppm3);
  std::ofstream output4(ppm4);
  std::ofstream output5(ppm5);
  std::ofstream output6(ppm6);
  std::ofstream output7(ppm7);
  std::ofstream output8(ppm8);
  std::ofstream output9(ppm9);
  std::ofstream output10(ppm10);
  std::ofstream output11(ppm11);
  std::ofstream output12(ppm12);
  std::ofstream output13(ppm13);
  std::ofstream output14(ppm14);

  //Check that all the files opened
  if (!(input&&output&&output2&&output3&&output4&&output5&&output6&&output7
        &&output8&&output9&&output10&&output11&&output12&&output13&&output14)){
    std::cerr << " The input/output could not be opened." << endl;
    return 1;
  }

  //Creates 14 Images from the input file
  Image doggo(input);
  Image sharp(doggo);
  Image blur(doggo);
  Image hflip(doggo);
  Image vflip(doggo);
  Image binary(doggo);
  Image sepia(doggo);
  Image gray(doggo);
  Image pic8(doggo);
  Image pic9(doggo);
  Image pic10(doggo);
  Image pic11(doggo);
  Image pic12(doggo);
  Image pic13(doggo);
  Image pic14(doggo);

  //sharpen
  Sharpen s;
  s.apply(sharp);
  sharp.write_to(output);
  //blur
  Blur b;
  b.apply(blur);
  blur.write_to(output2);
  //Hflip
  Hflip h;
  h.apply(hflip);
  hflip.write_to(output3);
  //vflip
  Vflip v;
  v.apply(vflip);
  vflip.write_to(output4);
  //Binary
  Binary bi;
  bi.apply(binary);
  binary.write_to(output5);
  //Sepia
  Sepia se;
  se.apply(sepia);
  sepia.write_to(output6);
  //Grayscale
  Grayscale g;
  g.apply(gray);
  gray.write_to(output7);
  //sharpen,binary,hflip
  vector <Filter*> set8 = {&s,&bi,&h};
  for (Filter* filter : set8){
    filter->apply(pic8);
  }
  pic8.write_to(output8);
  //sharpen,sepia,Vflip
  vector <Filter*> set9 = { &s, &se, &v };
  for (Filter* filter : set9){
    filter->apply(pic9);
  }
  pic9.write_to(output9);
  //sharpen,grayscale,Hflip
  vector <Filter*> set10 = {&s,&g,&h};
  for (Filter* filter : set10){
    filter->apply(pic10);
  }
  pic10.write_to(output10);
  //blur,grayscale,vfliprun:
  vector <Filter*> set11 = {&b,&g,&v};
  for (Filter* filter : set11){
    filter->apply(pic11);
  }
  pic11.write_to(output11);
  //blur,binary,hflip
  vector <Filter*> set12 = {&b,&bi,&h};
  for (Filter* filter : set12){
    filter->apply(pic12);
  }
  pic12.write_to(output12);
  //blur,sepia,Vflip
  vector <Filter*> set13 = {&b,&se,&v};
  for (Filter* filter : set13){
    filter->apply(pic13);
  }
  pic13.write_to(output13);
  //sharpen,sharpen,sepia
  vector <Filter*> set14 = {&s,&s,&se};
  for (Filter* filter : set14){
    filter->apply(pic14);
  }
  pic14.write_to(output14);

  //closing each of the input/output files
  input.close();
  output.close();
  output2.close();
  output3.close();
  output4.close();
  output5.close();
  output6.close();
  output7.close();
  output8.close();
  output9.close();
  output10.close();
  output11.close();
  output12.close();
  output13.close();
  output14.close();

  return 0;
}
