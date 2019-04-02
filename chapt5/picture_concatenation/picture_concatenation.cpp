#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//meassures the length of the largest string in a given vector.
string::size_type width(const vector<string>& v)
{
	string::size_type ret = 0;
	for(vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
		ret = max(ret, (*i).size());
	return ret;
}

//returns a framed version of the given image.
vector<string> frame(const vector<string>& message)
{
	vector<string> ret;
	//get width of the message to frame
	string::size_type message_width = width(message);
	
	//generate first line of image: border
	string border(message_width + 4, '*');
	ret.push_back(border);
	
	//write each row of message into the return, padded and bordered
	for(vector<string>::const_iterator i = message.begin(); i != message.end(); ++i)
		ret.push_back("* " + *i + string(message_width - (*i).size(), ' ') + " *");
	
	
	//tie off border with final line
	ret.push_back(border);
	
	return ret;
}

//prints the given image
void print_image(const vector<string>& image)
{
	for(vector<string>::const_iterator i = image.begin(); i != image.end(); ++i)
		cout << *i << endl;
}

//reads a number of lines into a vector from the input stream.
istream& read_words(istream& c, vector<string>& v)
{
	if(c) {
		string word;
		while(getline(c,word))
			v.push_back(word);
		c.clear();
	}
	return c;
}

//concatenate two images vertically, lining up along their left margins
vector<string> vcat(const vector<string>& image_1, const vector<string>& image_2)
{
	vector<string> ret;
	
	//copy the intirety of image_1 into ret
	ret = image_1;
	
	//now push the lines of image_2 onto the end of ret one-by-one to complete the image
	for(vector<string>::const_iterator i = image_2.begin(); i != image_2.end(); ++i)
		ret.push_back(*i);
	
	return ret;
}

//concatenate two images horizontally, lining up along their top edges
vector<string> hcat(const vector<string>& image_1, const vector<string>& image_2)
{
	vector<string> ret;
	//get the width of the first image
	string::size_type image_1_width = width(image_1);
	vector<string>::const_iterator i = image_1.begin();
	vector<string>::const_iterator j = image_2.begin();
	
	//push onto ret as many concatentated lines as possible before you
	//reach the last line of the image with the fewest lines.
	while(i != image_1.end() && j != image_2.end())
	{
		ret.push_back( *i + string(image_1_width - (*i).size(), ' ') + *j);
		++i;
		++j;
	}
	
	if(i == image_1.end())
		while(j != image_2.end())
		{
			ret.push_back(string(image_1_width, ' ') + *j);
			++j;
		}
	else 
		while(i != image_1.end())
		{
			ret.push_back(*i);
			++i;
		}

	return ret;
}

int main()
{
	vector<string> image_1, image_2;
	cout << "Enter lines for your first image:" << endl;
	read_words(cin, image_1);
	cout << "Enter lines for a second image" << endl;
	read_words(cin, image_2);
	print_image(hcat(frame(image_1), frame(image_2)));
	return 0;
}
