/// Overkillographic - transform images into bizarre absurdity.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/* Version 1.0.0
 ______________________________________________________________________________
/                                                                              \
|                     Have some folder ready with image(s)                     |
\______________________________________________________________________________/

* Download a YouTube video containing frames of your liking and use the OpenShot
  video editor to dispense those frames from the video, at an fps of you liking.
  OpenShot is available through apt, but that's crashy. Get it from the official
  website, set it as executable, and double-click to open.  If you have a decent
  processor and 8GB RAM, too fucking bad. Everything will crash with image sizes
  produced by this program; you may safely work with ~200 frames at a time.
* Overkillographic converts images to bmp, modifies bmp, & converts bmp to jpg.
* If you're using Devuan/Debian, you should already have mogrify available. Else
  you need to install it: apt install imagemagick
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to run the program  -  Software package repositories for GNU+Linux operating
systems have all the tools you can imagine. Open a terminal and use this command
as root to install Geany and g++ on your computer: apt install geany g++   Geany
is a fast & lightweight text editor and Integrated Development Environment where
you can write and run code. g++ is the GNU compiler for C++ which allows written
code to run. The compiler operates in the background and displays errors in your
code as you will see in the lower Geany box. Make a new folder somewhere on your
machine. Paste this code into Geany. For clarity in auditing, enable indentation
guides: go to View >> Show Indentation Guides. Save the document as anything.cpp
within the newly-created folder. Use these shortcuts to run the program: F9, F5.
You may paste over this code with other  .cpp files, or open a new tab & repeat.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to make an executable with g++  -  Save this program as anything.cpp, open a
terminal, and type g++ then space. Drag & drop this saved file into the terminal
and its directory will be  appended to your pending entry. Click on the terminal
and press enter.   a.out now resides in the user directory, you may rename it to
anything.  To run that executable, simply drag and drop it into a terminal, then
click on the terminal and press enter.  Reminder:  executable's effect-directory
is /home/user or where you put the executable. Opening  .cpp  files in Geany and
hitting F9 creates the same executable--movable, renameable, drag & droppable.*/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	//                               user knobs
	
	/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    ////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\      ///////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\        //////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\            ////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\              ///////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                  /////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\                      ///////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\                              ///////////////////////
	\\\\\\\\\\\\\\\\\\                                        ////////////////*/
	
	
	//                                                                                                           |
	bool pauses_of_2_seconds = false; //Default = false else pauses between each            slow if broken >     |
	//                                image operation to keep your storage cool.                                 |
	
	
	/*////////////////                                          \\\\\\\\\\\\\\\\
	///////////////////////                              \\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////                      \\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////                  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////              \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////            \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////////      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////////    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////////////  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	
	ifstream in_stream;
	ofstream out_stream;
	
	//Gets path to FOLDER from user.
	cout << "\nDrag & drop FOLDER into terminal or enter path:\n";
	char  path_to_file[10000];
	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';} //Fills path_to_file[] with null.
	cin.getline(path_to_file, 10000);
	if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
	
	//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/nikolay/my documents/'
	if(path_to_file[0] == '\'')
	{	for(int a = 0; a < 10000; a++)
		{	path_to_file[a] = path_to_file[a + 1];
			if(path_to_file[a] == '\'')
			{	path_to_file[a    ] = '\0';
				path_to_file[a + 1] = '\0';
				path_to_file[a + 2] = '\0';
				break;
			}
		}
	}
	
	//Checks if FOLDER exists.
	in_stream.open(path_to_file);
	if(in_stream.fail() == true) {in_stream.close(); cout << "\n\nNo such directory.\n";             return 0;}
	in_stream.close();
	
	//Gets location of the first encountered end-null coming from the left in path_to_file[].
	int path_to_file_null_bookmark;
	for(int a = 0; a < 10000; a++) {if(path_to_file[a] == '\0') {path_to_file_null_bookmark = a; break;}}
	
	//Gets list of file names from given directory.
	char ls[10000] = {"ls "};
	for(int a = 0; path_to_file[a] != '\0'; a++) {ls[a + 3] = path_to_file[a];} //Appends given path.
	ls[path_to_file_null_bookmark + 3] = ' '; //Appends commands.
	ls[path_to_file_null_bookmark + 4] = '>';
	ls[path_to_file_null_bookmark + 5] = ' ';
	ls[path_to_file_null_bookmark + 6] = 'f';
	system(ls);
	
	//Checks if FOLDER is empty.
	in_stream.open("f");
	char sniffed_one_file_character;
	in_stream.get(sniffed_one_file_character);
	if(in_stream.eof() == true) {in_stream.close(); cout << "\n\nNothing to process, the FOLDER is empty.\n"; return 0;}
	in_stream.close();
	
	//Counts number of images.
	long number_of_files = 0;
	char garbage_byte;
	char temp_garbage_byte;
	in_stream.open("f");
	in_stream.get(garbage_byte);
	for(; in_stream.eof() == false;)
	{	if(garbage_byte == '\n') {number_of_files++;}
		temp_garbage_byte = garbage_byte;
		in_stream.get(garbage_byte);
	}
	in_stream.close();
	
	if(temp_garbage_byte != '\n') {number_of_files++;}
	
	//Begins.
	cout << "\n";
	path_to_file[path_to_file_null_bookmark] = '/';
	path_to_file_null_bookmark++;
	system("mkdir -p New_images");
	long file_name_bytes_read_bookmark = -1;
	for(long a = 0; a < number_of_files; a++)
	{	//Pauses for keeping cool.
		if(pauses_of_2_seconds == true) {system("sleep 2");}
		
		//..........Loads path_to_file[] with file name.
		in_stream.open("f");
		file_name_bytes_read_bookmark++;
		for(long b = 0; b < file_name_bytes_read_bookmark; b++) {in_stream.get(garbage_byte);} //..........Skips name Bytes that have been read.
		
		int path_to_file_write_bookmark = path_to_file_null_bookmark;
		in_stream.get(garbage_byte);
		for(; garbage_byte != '\n';)
		{	path_to_file[path_to_file_write_bookmark] = garbage_byte;
			path_to_file_write_bookmark++;
			file_name_bytes_read_bookmark++;
			in_stream.get(garbage_byte);
			
			if(in_stream.eof() == true) {break;}
		}
		in_stream.close();
		
		//Copies entire image to working directory.
		in_stream.open(path_to_file);
		out_stream.open("temp_image_copy");
		in_stream.get(garbage_byte);
		for(int b = 0; in_stream.eof() == false; b++)
		{	out_stream.put(garbage_byte);
			in_stream.get(garbage_byte);
		}
		in_stream.close();
		out_stream.close();
		
		//Converts image to bmp.
		system("mogrify -format bmp temp_image_copy");
		
		//Prepares new stream to new folder.
		char same_name[10000] = {"New_images/"};
		int temp_null = path_to_file_null_bookmark;
		for(int b = 11; path_to_file[temp_null] != '\0'; b++)
		{	same_name[b] = path_to_file[temp_null];
			temp_null++;
		}
		
		/*Copies first 10,000 bmp Bytes to folder New_images. These first bytes
		decide image height & width so even if you accidentally write terabytes
		to the file after these bytes, it will be ignored. Only bytes needed to
		finish the image are taken--Byte for Byte where if you run out of Bytes,
		the rest of the image is simply black yet still sized as the original.*/
		in_stream.open("temp_image_copy.bmp");
		out_stream.open(same_name);
		for(int b = 0; b < 10000; b++)
		{	in_stream.get(garbage_byte);
			out_stream.put(garbage_byte);
		}
		
		//Grabs & modifies remaining image Bytes.
		in_stream.get(garbage_byte);
		for(long long temp; in_stream.eof() == false;)
		{	//Normal conversion to values 0-255.
			temp = (garbage_byte);
			if(temp < 0) {temp += 256;}
			
			//Modification to the Byte. Poke it as you wish.
			/*      ______________________________________________________
			       /                                                      \
			      |  ÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅÅ  |
			      |  ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤ MODIFY  BYTE ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤  |
			      |  ¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥¥  |
			       \______________________________________________________/
			*/
			temp *= temp;
			
			//Normalizing Byte.
			if(temp < 0) {temp = 0;}
			temp %= 256;
			
			//Normal conversion before write-back.
			if(temp < 128) {out_stream.put(temp      );}
			else           {out_stream.put(temp - 256);}
			
			in_stream.get(garbage_byte);
		}
		in_stream.close();
		out_stream.close();
		
		cout << (a + 1) << " of " << number_of_files << " done.\n";
	}
	
	remove("f");
	remove("temp_image_copy");
	remove("temp_image_copy.bmp");
}
