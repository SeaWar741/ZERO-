//Begin page main
//Declare any variables shared

float myState[12];

float posA[3];
float target[3];

float targetRate[3];
float stop[3];

int counter;
int step;

void init(){ //delare initial values
	
	posA[0]=0.25;
	posA[1]=0.45;
	posA[2]=0.0;
	
	targetRate[0]=0.0;
	targetRate[1]=0.0;
	targetRate[2]=-40*PI/180;
	
	stop[0]=0.0;
	stop[1]=0.0;
	stop[2]=0.0;

}

void loop(){	//This function is called once per second
	
	api.getMyZRState(myState);                  //conisgue datos de posición
	target[0]=0.25;                             //marca en x un objetivo
	
	if (myState[0] < target[0]){                // pide que se mueva a la posición A
	    api.setPositionTarget(posA);
	}
	if (myState[0] > target[0]){                //pide que se mantenga en la posición A
	    api.setPositionTarget(posA);
	}
	if (myState[0] >= posA[0]) {                //pide que empiece a rotar, consiga el numero de drills atual de la posA y active el drill
	    api.setAttRateTarget(targetRate);
	    game.getDrillEnabled();
	    game.getDrills(myState);
	}
	if ((myState[0] >= posA[0]) && (game.getDrills(myState) <= 1)){ //si se cumplen las dos condiciones empieza drill y revisa si hay muestras
	    game.startDrill();
	    game.checkSample();
	}
    if (game.checkSample()==true){              //recoge la muestra y marca la cantidad conseguida
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 2){         //si tienes dos muestras deten tu rotación
        api.setAttRateTarget(stop);
    }
    if (myState[11] == stop[0]){                //si te detuviste apaga el drill
        game.stopDrill();
    }
}
//End page main
