//Begin page Position A
void go_to_positionA(){
    target[0]=0.57;
    if (myZRState[0] < target[0]){
            api.setPositionTarget(positionA);
        }
        else {
           step++;
        }
}
//End page Position A
//Begin page Position C
void go_to_positionC(){
    target[0]=-0.27;
    if (myZRState[0] > target[0]){
            api.setPositionTarget(positionC);
        }
        else {
           step++;
        }
}
//End page Position C
//Begin page Position D
void go_to_positionD(){
    target[0]=-0.03;
    if (myZRState[0] < target[0]){
            api.setPositionTarget(positionD);
        }
        else {
            step++;
        }
}
//End page Position D
//Begin page main
//Inicio programa

//Variables generales
float positionA[3];
float positionC[3];
float positionD[3];
float myZRState[12];
float target[3];
int step;

float targetRate[3];
float stop[3];

float startDrill();
float checkSample();
float pickupSample();

void init(){

        positionA[0]=0.6;
        positionA[1]=0.6;
        positionA[2]=0.0;
        
        positionC[0]=-0.3;
        positionC[1]=0.6;
        positionC[2]=0.0;
        
        positionD[0]=0.0;
        positionD[1]=0.0;
        positionD[2]=0.0;
        
        targetRate[0]=0.0;
    	targetRate[1]=0.0;
    	targetRate[2]=-40*PI/180;
	    
    	stop[0]=0.0;
    	stop[1]=0.0;
    	stop[2]=0.0;
        
        
}

void loop(){


        api.getMyZRState(myZRState);
        
        if (step==0){
            go_to_positionA();
            
            if (myZRState[0] >= positionA[0]) {                //pide que empiece a rotar, consiga el numero de drills atual de la posA y active el drill
	        api.setAttRateTarget(targetRate);
	        game.getDrillEnabled();
	        game.getDrills(myZRState);
        	}
    	    if ((myZRState[0] >= positionA[0]) && (game.getDrills(myZRState) <= 1)){ //si se cumplen las dos condiciones empieza drill y revisa si hay muestras
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
            if (myZRState[11] == stop[0]){                //si te detuviste apaga el drill
        game.stopDrill();
        }
        }
        
        if (step==1){
            go_to_positionC();
        }
        
        if (step==2){
            go_to_positionD();
        }
        
        else {
            step=0;
        }
        
        DEBUG(("Paso # %d", step));
}

//Fin del codigo

//End page main
