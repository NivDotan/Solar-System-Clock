#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initUI();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI() {
    mainWidget = new QWidget();

    for(int i=0; i < Coords.size(); i++){

        //NewPlanet = new PlanetPaint;
        //NewPlanet->setParent(mainWidget);
        //NewPlanet->move(i.getX()*10, i.getY()*10);


    }

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    int tmpSizeOfPlanet = 15;//There is an offset of 4 pix because of the init of PlanetPaint so the picture wouldnt get cut



     //std::cout <<"Screen size is:"<< height;
     //std::cout <<"Screen size is:"<< width;

    NewPlanet1 = new PlanetPaint;
    NewPlanet1->setParent(mainWidget);
    NewPlanet1->move(((Coords.at(0)).GetXCoord()*350)+(width/2)-tmpSizeOfPlanet, ((Coords.at(0)).GetYCoord()*350+(height/2))-tmpSizeOfPlanet);

    NewPlanet2 = new PlanetPaint;
    NewPlanet2->setParent(mainWidget);
    NewPlanet2->move(((Coords.at(1)).GetXCoord()*350)+(width/2)-tmpSizeOfPlanet, ((Coords.at(1)).GetYCoord()*350+(height/2))-tmpSizeOfPlanet);

    NewPlanet3 = new PlanetPaint;
    NewPlanet3->setParent(mainWidget);
    NewPlanet3->move(((Coords.at(2)).GetXCoord()*350)+(width/2)-tmpSizeOfPlanet,((Coords.at(2)).GetYCoord()*350+(height/2))-tmpSizeOfPlanet);

    NewPlanet4 = new PlanetPaint;
    NewPlanet4->setParent(mainWidget);
    NewPlanet4->move(((Coords.at(3)).GetXCoord()*350)+(width/2)-tmpSizeOfPlanet, ((Coords.at(3)).GetYCoord()*350+(height/2))-tmpSizeOfPlanet);

    Sun = new PlanetPaint;
    Sun->setParent(mainWidget);
    Sun->move((width/2)-tmpSizeOfPlanet,(height/2)-tmpSizeOfPlanet);

    //Mercury Orbit
    Orbit = new OrbitalPaint;
    Orbit->setParent(mainWidget);
    Orbit->Setwidth(258);
    Orbit->Setheight(270);
    Orbit->Setmargin(50);
    //Orbit->move((width/2)-129,(height/2)-135-50);//50
    Orbit->setAngle(-14.5);
    Orbit->SetAdjusted(1.5,1.5,-2,-2);
    Orbit->move(0,0);
    Orbit->move((width/2)-129,(height/2)-135-50);//50

    //Change the orbits to this: https://stackoverflow.com/questions/14521477/setting-padding-and-margin-to-0-doesn%C2%B4t-work
    //Explantion(also for angle): https://het.as.utexas.edu/HET/Software/html/stylesheet-customizing.html, https://het.as.utexas.edu/HET/Software/html/stylesheet-reference.html, https://het.as.utexas.edu/HET/Software/html/stylesheet-examples.html

    //Venus Orbit
    Orbit2 = new OrbitalPaint;
    Orbit2->setParent(mainWidget);
    Orbit2->Setwidth(508);//508
    Orbit2->Setheight(506);//506
    Orbit2->Setmargin(0);//Margin need to be -30
    Orbit2->setStyleSheet("Margin: 200px,Padding: 200px, Border: 200px");
    Orbit2->repaint();
    Orbit2->SetAdjusted(1.5,1.5,-2,-2);
    Orbit2->setGeometry(0,0,508,506);
    //Orbit2->move((width/2)-(508/2),(height/2)-(506/2)-150);
    Orbit2->move(0,0);
    Orbit2->move((width/2)-(508/2),(height/2)-(506/2)-0);

    //Earth Orbit
    Orbit3 = new OrbitalPaint;
    Orbit3->setParent(mainWidget);
    Orbit3->Setwidth(700);
    Orbit3->Setheight(696);
    Orbit3->Setmargin(0);
    //
    Orbit3->SetAdjusted(1.5,1.5,-2,-2);
    Orbit3->setGeometry(0,0,700,696);
    Orbit3->move(0,0);//(0,0)
    Orbit3->move((width/2)-(700/2),(height/2)-(696/2)-0);//(0,0)
    //Mars Orbit
    /*
    Orbit2 = new OrbitalPaint;
    Orbit2->setParent(mainWidget);
    Orbit2->Setwidth(1069);
    Orbit2->Setheight(1077);
    Orbit2->move((width/2)-(700/2),(height/2)-(696/2)-50);//(0,0)*/



    //Build a general Plant class for the function, enter a daclartion for abstarct function(virtual) of the 2 functions -> DONE
    //Need to ReCalibrate the orbit place for each plant, we will create 4 parameters and send them to OrbitalPaint -> DONE
    //Build a function for calculating the orbit path and getting them into mainwindow using a vector like the plants -> DONE - Need to understant why it calculate this for Mars
    //Build Earth and Mars Orbits -> Currently building

    //Understand the setAngle and implment it
    //Check if they are the real Orbits using: https://www.universetoday.com/81575/venus-has-a-moon/
    //Add Saturn, Jupiter and check Neptun and Uranus
    //Change the color and add photos
    //Make the lines more HD -> DONE



    //m->setFloat(10);
    //m->doPainting();

    mainWidget->show();
    hide();//this will disappear main window


}

void MainWindow::SetVecor(vector<CartesianCoord> AllTheCoord){
    Coords = AllTheCoord;
    std::cout <<"size is:"<< AllTheCoord.size();
    std::cout <<"size is:"<< Coords.size();
    std::cout << "size is:"<< Coords.at(0).GetXCoord();
}

void MainWindow::ShowPlanets(){
    initUI();
}

