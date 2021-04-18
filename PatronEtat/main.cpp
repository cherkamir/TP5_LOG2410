#include "Etat.h"
#include "Application.h"
#include"AnalyseEtPartition.h"
#include <iostream>

using namespace std;



void Client()
{
    Application *app = new Application(new Analyse);
    app->analyserperformance();
    app->scannerPartition();
    delete app;
}

int main()
{
    Client();
    return 0;
}