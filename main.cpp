#include "mainwindow.h"
#include "earth.h"
#include "Mars.h"
#include "Venus.h"
#include "Mercury.h"
#include <QApplication>
#include <vector>
#include "CartesianCoord.h"
#include "Planet.h"
using namespace std;


int calculatingOrbit(Planet tmpPlant, int year, int day, int month, int OrbitTime ){

    int LongFeb = 0;
    vector<double> tmpArray2;
    tmpPlant.SetDate(year, month, day);
    tmpPlant.CalculateOrbit();
    double Max1, Min2, tmp, tmpX1, tmpY1, tmpX2, tmpY2, tmp2X1, tmp2Y1, tmp2X2, tmp2Y2, LaneLen, tmp1,tmpLenx1, tmpLeny1, tmpLenx2, tmpLeny2;
    int Place1,Place2;
    LaneLen = 0;
    Max1 = Min2 = 0.0;

    if (year%4 == 0){
        LongFeb = 1;
    }
    for(int i=1,j=1,DayCount = 0;;DayCount++, j++){
    //for(int i= 1, j =1, DayCount = 0; ;j++;DayCount++){

         if (j == 32 &&( i==1 || i == 3  || i == 5  || i == 7  || i == 8  || i == 10  || i == 12)){
             if (i==12){
                 j = 1;
                 i = 1;
             }
             else{
                 j = 1;
                 i = i + 1;
             }

         }
         if (j == 31 &&( i==4 || i == 6  || i ==9  || i == 11)){
             j = 1;
             i = i + 1;
         }

         if(j == 29 &&( i==2) && LongFeb == 0){
             j = 1;
             i = i + 1;
         }
         if (j == 30 &&( i==2) && LongFeb == 1){
             j = 1;
             i = i + 1;
         }


         tmpPlant.SetDate(year, i, j);
         tmpPlant.CalculateOrbit();
         tmpArray2.push_back(tmpPlant.GetX());
         tmpArray2.push_back(tmpPlant.GetY());
         if (OrbitTime == DayCount){
              break;
          }

        //cout << j << " " << i<< " " << DayCount;


     }



     for(int i = 0;i<tmpArray2.size() ; i = i+ 2){

             if (Max1 < (tmp =  sqrt(pow(tmpArray2.at(i),2)+pow(tmpArray2.at(i+1),2)))){
                 Max1 = tmp;
                 tmpX1 = tmpArray2.at(i);
                 tmpY1 = tmpArray2.at(i+1);
                  Place1 = i;

             }

             else if (Min2 == 0||Min2 > (tmp =  sqrt(pow(tmpArray2.at(i),2)+pow(tmpArray2.at(i+1),2)))){
                     Min2 = tmp;
                     tmp2X1 = tmpArray2.at(i);
                     tmp2Y1 = tmpArray2.at(i+1);
                      Place2 = i;

             }



     }


     LaneLen = 0;

     for(int i = 0 ,j = tmpArray2.size()/2 ; i<tmpArray2.size()/2-1 ; i = i+ 2, j = j + 2){

         if (LaneLen == 0 || LaneLen > (tmp1 =  sqrt(pow(((tmpArray2.at(i)*100)-tmpArray2.at(j)*100),2)+pow(((tmpArray2.at(i+1)*100)-tmpArray2.at(j+1)*100),2)))){
             LaneLen = sqrt(pow(((tmpArray2.at(i)*100)-tmpArray2.at(j)*100),2)+pow(((tmpArray2.at(i+1)*100)-tmpArray2.at(j+1)*100),2));

             tmpLenx1 = tmpArray2.at(i);
             tmpLeny1 = tmpArray2.at(i+1);
             tmpLenx2 = tmpArray2.at(j);
             tmpLeny2 = tmpArray2.at(j+1);

         }
     }
    cout << "---------------------hf----------------------------------------"<< endl;
     cout << "---------------------In calculatingOrbit----------------------------------------"<< endl;

     cout << tmpX1 << "   " << tmpY1 << "   " << Place1 << " " << tmpArray2.size() << " " << Max1 << endl;
     cout << tmp2X1 << "   " << tmp2Y1  << "   " << Place2 << " " << Min2 << endl;
     //cout << ((atan(0.751192/0.179895)*180)/3.1415) << "   "  << "   " << endl;//0.179895, 0.751192 and we get the alpha For the ANGLE
     cout << tmpLenx1 << "   " << tmpLeny1  << "   " << tmpLenx2 << " " << tmpLeny2 << " " << LaneLen/100 << endl;

    return 1;
}





//https://www.bogotobogo.com/Qt/Qt5_QPainter_Transformation.php
int main(int argc, char *argv[])
{
    /*
    Mercury Mercury;
    Mercury.SetDate(1976, 7, 20);
    Mercury.CalculateOrbit();
    Venus Venus;
    Venus.SetDate(1976, 7, 20);
    Venus.CalculateOrbit();
    Earth Terra;
    Terra.SetDate(1976,7,20);
    Terra.CalculateOrbit();
    Mars Mars;
    Mars.SetDate(1976, 7, 20);
    Mars.CalculateOrbit();*/

    Planet Mercury;
    Mercury.SetOrbitParameters(48.3313,(3.24587E-5),7.0047,(5.00E-8),29.1241 , (1.01444E-5), 0.387098, 0.205635 , (5.59E-10), 168.6562 , 4.0923344368);
    Mercury.SetDate(1976, 7, 20);
    Mercury.CalculateOrbit();

    Planet Venus;
    Venus.SetOrbitParameters(76.6799 , (2.46590E-5),3.3946 , (2.75E-8) ,54.8910 , (1.38374E-5), 0.723330, 0.006773 , -(1.302E-9),48.0052 , 1.6021302244);
    Venus.SetDate(1976, 7, 20);
    Venus.CalculateOrbit();

    Planet Terra;
    Terra.SetOrbitParameters(0,0,0,0,282.9404 , (4.70935E-5), 1.0000002 ,0.016709 , -(1.151E-9), 356.0470 , 0.9856002585);
    Terra.SetDate(1976, 7, 20);
    Terra.CalculateOrbit();

    Planet Mars;
    Mars.SetOrbitParameters(49.5574, (2.11081E-5),  1.8497, -(1.78E-8), 286.5016 , (2.92961E-5), 1.523688,  0.093405 , (2.516E-9), 18.6021 , 0.5240207766);
    Mars.SetDate(1976, 7, 20);
    Mars.CalculateOrbit();

    calculatingOrbit(Mercury,2000,1,1,88);
    calculatingOrbit(Venus,2000,1,1,225);
    calculatingOrbit(Terra,2000,1,1,365);
    calculatingOrbit(Mars,2000,1,1,687);

    double Max1, Min2, tmp, tmpX1, tmpY1, tmpX2, tmpY2, tmp2X1, tmp2Y1, tmp2X2, tmp2Y2;
    Max1 = Min2 = 0.0;
    vector<double> tmpArray;

    Mercury.SetDate(2000, 1, 1);
    Mercury.CalculateOrbit();
    int DAYS = 0;
    for(int i= 1, j =1; i<4;j++){
        if (j == 29 && (i == 3)){
            break;
        }
        if (j == 32 &&( i==1 || i == 3  || i == 5  || i == 7  || i == 8  || i == 10  || i == 12)){
            j = 1;
            i = i + 1;
        }
        if (j == 31 &&( i==4 || i == 6  || i ==9  || i == 11)){
            j = 1;
            i = i + 1;
        }
        if (j == 30 &&( i==2)){
            j = 1;
            i = i + 1;
        }

        Mercury.SetDate(2000, i, j);
        Mercury.CalculateOrbit();
        tmpArray.push_back(Mercury.GetX());
        tmpArray.push_back(Mercury.GetY());
        DAYS++;
        //cout << " " << j << " " << i << " "<< DAYS ;



    }//include 28/03

    int Place1,Place2;
    for(int i = 0;i<tmpArray.size() ; i = i+ 2){

                if (Max1 < (tmp =  sqrt(pow(tmpArray.at(i),2)+pow(tmpArray.at(i+1),2)))){
                Max1 = tmp;
                tmpX1 = tmpArray.at(i);
                tmpY1 = tmpArray.at(i+1);
                 Place1 = i;

            }

            else if (Min2 == 0||Min2 > (tmp =  sqrt(pow(tmpArray.at(i),2)+pow(tmpArray.at(i+1),2)))){
                    Min2 = tmp;
                    tmp2X1 = tmpArray.at(i);
                    tmp2Y1 = tmpArray.at(i+1);
                     Place2 = i;

            }



    }

    double LaneLen, tmp1,tmpLenx1, tmpLeny1, tmpLenx2, tmpLeny2;
    LaneLen = 0;

    for(int i = 0 ,j = tmpArray.size()/2 ; i<tmpArray.size()/2 ; i = i+ 2, j = j + 2){

        if (LaneLen == 0 || LaneLen > (tmp1 =  sqrt(pow(((tmpArray.at(i)*100)-tmpArray.at(j)*100),2)+pow(((tmpArray.at(i+1)*100)-tmpArray.at(j+1)*100),2)))){
            LaneLen = sqrt(pow(((tmpArray.at(i)*100)-tmpArray.at(j)*100),2)+pow(((tmpArray.at(i+1)*100)-tmpArray.at(j+1)*100),2));

            tmpLenx1 = tmpArray.at(i);
            tmpLeny1 = tmpArray.at(i+1);
            tmpLenx2 = tmpArray.at(j);
            tmpLeny2 = tmpArray.at(j+1);

        }
    }

    cout << "-------------------------------------------------------------"<< endl;

    cout << tmpX1 << "   " << tmpY1 << "   " << Place1 << " " << tmpArray.size() << " " << Max1 << endl;
    cout << tmp2X1 << "   " << tmp2Y1  << "   " << Place2 << " " << Min2 << endl;
    //cout << ((atan(0.751192/0.179895)*180)/3.1415) << "   "  << "   " << endl;//0.179895, 0.751192 and we get the alpha
    cout << tmpLenx1 << "   " << tmpLeny1  << "   " << tmpLenx2 << " " << tmpLeny2 << " " << LaneLen/100 << endl;


    // ---------------------------------------------VENUS ORBIT-------------------------------------------------------------------------------
   vector<double> tmpArray2;
    Venus.SetDate(2000, 1, 1);
    Venus.CalculateOrbit();

    for(int i= 1, j =1; ;j++){
        if (j == 12 && (i == 8)){
            break;
        }
        if (j == 32 &&( i==1 || i == 3  || i == 5  || i == 7  || i == 8  || i == 10  || i == 12)){
            j = 1;
            i = i + 1;
        }
        if (j == 31 &&( i==4 || i == 6  || i ==9  || i == 11)){
            j = 1;
            i = i + 1;
        }
        if (j == 30 &&( i==2)){

            j = 1;
            i = i + 1;
        }

        Venus.SetDate(2000, i, j);
        Venus.CalculateOrbit();
        tmpArray2.push_back(Venus.GetX());
        tmpArray2.push_back(Venus.GetY());
        DAYS++;
        //cout << " " << j << " " << i<< " " << DAYS;


    }//include 11/09


    for(int i = 0;i<tmpArray2.size() ; i = i+ 2){

                if (Max1 < (tmp =  sqrt(pow(tmpArray2.at(i),2)+pow(tmpArray2.at(i+1),2)))){
                Max1 = tmp;
                tmpX1 = tmpArray2.at(i);
                tmpY1 = tmpArray2.at(i+1);
                 Place1 = i;

            }

            else if (Min2 == 0||Min2 > (tmp =  sqrt(pow(tmpArray2.at(i),2)+pow(tmpArray2.at(i+1),2)))){
                    Min2 = tmp;
                    tmp2X1 = tmpArray2.at(i);
                    tmp2Y1 = tmpArray2.at(i+1);
                     Place2 = i;

            }



    }


    LaneLen = 0;
    cout << tmpArray2.size() << endl;
     cout << tmpArray2.at(100) <<" " << tmpArray2.at(101) << endl;
    for(int i = 0 ,j = tmpArray2.size()/2 ; i<tmpArray2.size()/2 ; i = i+ 2, j = j + 2){

        if (LaneLen == 0 || LaneLen > (tmp1 =  sqrt(pow(((tmpArray2.at(i)*100)-tmpArray2.at(j)*100),2)+pow(((tmpArray2.at(i+1)*100)-tmpArray2.at(j+1)*100),2)))){
            LaneLen = sqrt(pow(((tmpArray2.at(i)*100)-tmpArray2.at(j)*100),2)+pow(((tmpArray2.at(i+1)*100)-tmpArray2.at(j+1)*100),2));

            tmpLenx1 = tmpArray2.at(i);
            tmpLeny1 = tmpArray2.at(i+1);
            tmpLenx2 = tmpArray2.at(j);
            tmpLeny2 = tmpArray2.at(j+1);

        }
    }

    cout << "-------------------------------------------------------------"<< endl;

    cout << tmpX1 << "   " << tmpY1 << "   " << Place1 << " " << tmpArray2.size() << " " << Max1 << endl;
    cout << tmp2X1 << "   " << tmp2Y1  << "   " << Place2 << " " << Min2 << endl;
    //cout << ((atan(0.751192/0.179895)*180)/3.1415) << "   "  << "   " << endl;//0.179895, 0.751192 and we get the alpha For the ANGLE
    cout << tmpLenx1 << "   " << tmpLeny1  << "   " << tmpLenx2 << " " << tmpLeny2 << " " << LaneLen/100 << endl;

    // -------------------------------------------------------------------------------------------------------------------------------------------------------------------









    Mercury.SetDate(2000, 1, 1);
    Mercury.CalculateOrbit();
    Venus.SetDate(2000, 1, 1);
    Venus.CalculateOrbit();

    CartesianCoord MercuryCoord = CartesianCoord(Mercury.GetX(), Mercury.GetY(), "Mercury");
    CartesianCoord VenusCoord = CartesianCoord(Venus.GetX(), Venus.GetY(), "Venus");
    CartesianCoord TerraCoord = CartesianCoord(Terra.GetX(), Terra.GetY(), "Terra");
    CartesianCoord MarsCoord = CartesianCoord(Mars.GetX(), Mars.GetY(), "Mars");

    vector<CartesianCoord> AllTheCoord = {MercuryCoord, VenusCoord, TerraCoord, MarsCoord};

    QApplication a(argc, argv);
    MainWindow w;
    w.SetVecor(AllTheCoord);
    w.ShowPlanets();
    w.show();
    return a.exec();
}


