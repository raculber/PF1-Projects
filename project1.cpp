// Program calculates the volume, surface areas, and mass of toy tops
#include <iostream>
#include <cmath> 
using namespace std; 
int main()
{
	double rad1, rad2, height;
	const double PI = M_PI;
	cout << "Enter the radius value for the large sphere: "; 
	cin >> rad1; // Radius of large sphere
	cout << "Enter the radius value for the half sphere: ";
	cin >> rad2; // Radius of cylinder and half sphere
	cout << "Enter the height of the cylinder: ";
	cin >> height;// Height of cylinder
        // S1 = large sphere C = cylinder S2 = small sphere
	double volumeS1, volumeC, volumeS2, volumeAll;
	double areaS1, areaC, areaS2, areaAll; 
	const double GOLD_DENS = 19.32;
	const double SILVER_DENS = 10.5; 
	const double STEEL_DENS = 8.05; 
	double massTopG, massTopSil, massTopSt; 
	volumeS1 = (4.0*PI*rad1*rad1*rad1)/3.0;
        cout << "Volume of large sphere: " << volumeS1 << endl; 
        areaS1 = 4.0*PI*rad1*rad1; 
        cout << "Area of large sphere: " << areaS1  << endl;
        volumeC = PI*height*rad2*rad2;
        cout << "Volume of cylinder: " << volumeC << endl;
	areaC = (2.0*PI*height*rad2)+(2.0*PI*rad2*rad2);
        cout << "Area of cylinder: " << areaC << endl;
	volumeS2 = (2.0*PI*rad2*rad2*rad2)/3.0; // Volume formula for a hemisphere
        cout << "Volume of half sphere: " << volumeS2 << endl;
	areaS2 = 2.0*PI*rad2*rad2; // Area formula for a hemisphere
        cout << "Area of half sphere: " << areaS2 << endl;
	volumeAll = volumeS1 + volumeC + volumeS2; //Total volume of toy top
        cout << "Volume of toy top: " << volumeAll << endl;
	areaAll = areaS1 + areaC + areaS2; // Total area of toy top
	areaAll = areaAll - (PI * rad2 * rad2) - (PI * rad2 *rad2); //Accounts for surface area lost upon attachment 
	cout << "Total surface area of toy top: " << areaAll << endl;
        massTopG = volumeAll * GOLD_DENS;
        cout << "Mass with gold: " << massTopG << endl; 
	massTopSil = volumeAll * SILVER_DENS; 
        cout << "Mass with silver: " << massTopSil << endl;
	massTopSt = volumeAll * STEEL_DENS; 	
        cout << "Mass with steel: " << massTopSt << endl;
}
