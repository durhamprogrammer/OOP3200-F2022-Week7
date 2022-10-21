#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>


#include "Vector2D.h"

template<typename T>
void Vector2DWrite(Vector2D<T> point)
{
	std::ofstream Vector2DOutstream("Vectors.dat", std::ios::out);
	Vector2DOutstream << point.ToString() << std::endl;

	Vector2DOutstream.close();
}

template<typename T>
Vector2D<T> Vector2DRead()
{
	std::ifstream Vector2DInStream("Vectors.dat", std::ios::in);
	Vector2D<float> temp_point = Vector2D<T>::Zero();
	Vector2DInStream >> temp_point;

	Vector2DInStream.close();

	return temp_point;
}

template<typename T>
std::vector<Vector2D<T>*> Vector2DArrayRead(const std::string& file_name)
{
	std::ifstream Vector2DInStream(file_name, std::ios::in);

	std::vector<Vector2D<T>*> points;

	auto* temp_point = new Vector2D<T>();
	while(Vector2DInStream >> *temp_point)
	{
		points.push_back(new Vector2D<T>(temp_point->GetX(), temp_point->GetY()));
	}

	Vector2DInStream.close();

	return points;
}

template<typename T>
void PrintVector2DArray(std::vector<Vector2D<T>*> points)
{
	for (auto point : points)
	{
		std::cout << point->ToString() << std::endl;
	}
}


int main()
{
	// Case 1: Read an Array of Vector2D "float" types and store it in std::vector
	const auto points = Vector2DArrayRead<float>("Vectors.dat");
	PrintVector2DArray(points);

	std::map<std::string, Vector2D<float>*> vectorAtlas;
	vectorAtlas["AA"] = new Vector2D<float>(); // stores a Vector2D with a (0.0f, 0.0f) value
	vectorAtlas["AB"] = new Vector2D<float>(12.0f, 24.0f);


	try
	{
		for (const auto element : vectorAtlas)
		{
			std::cout << element.second->ToString() << std::endl;
		}
	}
	catch(std::exception exception)
	{
		std::cout << exception.what() << std::endl;
	}
	

	try
	{
		/************************
		 *	DECLARATIONS
		 ************************/



		
		/******************************************************************************
		 *	Reading Labels/Points into the Map:
		 *	Attempt to open the data file.  If the data file opens, read a label,
		 *	followed by a point and insert them into the map using the label as the key.
		 *	Repeat until all the data is read and close the file. If the data file did
		 *	not open, tell the user and remind them to check that the file exists. If
		 *	the file opened but the map is empty after the input loop, report that to
		 *	the user and remind them to check that the file contains valid data in
		 *	the correct format. Only continue processing if the file was opened and the
		 *	map is not empty.
		 ******************************************************************************/

		

		/******************************************************************************
		 *	Determine the Total Distance Between All Points in Order:
		 *	Use an iterator and a loop to traverse each label/point in the map. For
		 *	each label/point, determine the distance from that point to the previous
		 *	point (or next point depending on how you implement this) and add that
		 *	distance to a total.  Note that the Vector2D class includes a static 
		 *	distance function to determine the distance between two Vector2D
		 *	objects, so you should not need to use any complicated math here.  Report
		 *	to the user how many points the map contains and what the total distance is.
		 ******************************************************************************/

				

		/******************************************************************************
		 *	Determine the Distance Between the Start Point and a User Selected Point:
		 *	Prompt the user to enter a label or to enter "quit" to end.  If the user
		 *	entered anything other than "quit", attempt to find the label they entered
		 *	in the map. If it was found, report the distance between the point for the
		 *	label they entered and the start point (i.e. the point labeled "AA").
		 *	Otherwise, tell the user that the label they entered is not in the map.
		 *	Repeat these steps until the user enters "quit".
		 ******************************************************************************/
		
	}
	/******************************************************************************
	 *	Exception Handling:
	 *	Catch any std::exception thrown. Report to the user that a run-time error
	 *	occurred and show what exception was thrown.
	 ******************************************************************************/
	catch(...)  // an exception was thrown
	{
		
	}

	// END-OF-PROGRAM
	
	return 0;
}

