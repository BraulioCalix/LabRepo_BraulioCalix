#include <ncurses.h>
#include <fstream>
using std::ofstream;
#include <iostream>
using namespace std;
int main(){
    char usuar[24]="home";
    char maquin[24]="vm-gauss";
    bool menu=true;
    char document[256];
    string archivos="";
    while(menu==true){
    initscr();//empieza
    char accion[30];
    if(has_colors()){
        start_color();
        init_pair(1,COLOR_GREEN,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("%s",usuar);
        refresh();
        printw("@%s",maquin);    
        refresh();
        attroff(COLOR_PAIR(1));
        refresh();
    }
    printw(":");
    refresh();
    getstr(accion);
    //printw("%s",accion);
    refresh();
    if (accion[0]=='e'&&accion[1]=='x'&&accion[2]=='i'&&accion[3]=='t'){
        menu=false;
        refresh();
    }
    if (accion[0]=='c'&&accion[1]=='h'&&accion[2]=='a'&&accion[3]=='n'&&accion[4]=='g'&&accion[5]=='e'&&accion[6]=='U'&&accion[7]=='s'&&accion[8]=='e'&&accion[9]=='r'){
        //printw("user");
        int cont=0;
        for (int i = 11; i < 30; i++){
            usuar[cont]=accion[i];
            cont++;
        }
                
        refresh();
    }
    if (accion[0]=='c'&&accion[1]=='h'&&accion[2]=='a'&&accion[3]=='n'&&accion[4]=='g'&&accion[5]=='e'&&accion[6]=='M'&&accion[7]=='a'&&accion[8]=='c'&&accion[9]=='h'&&accion[10]=='i'&&accion[11]=='n'&&accion[12]=='e'){
        //printw("user");
        int cont=0;
        for (int i = 14; i < 30; i++){
            maquin[cont]=accion[i];
            cont++;
        }
                
        refresh();
    }
    if (accion[0]=='c'&&accion[1]=='l'&&accion[2]=='e'&&accion[3]=='a'&&accion[4]=='r'){
        clear();     
        refresh();
    }
    if(accion[0]=='m'&&accion[1]=='k'&&accion[2]=='d'&&accion[3]=='i'&&accion[4]=='r'){
        int cont=0;
        for (int i = 14; i < 30; i++){
            document[cont]=accion[i];
            cont++;
        }

    }
    if (accion[0]=='f'&&accion[1]=='i'&&accion[2]=='l'&&accion[3]=='e'){
        char nombre[20];
        int cont=0;
        for (int i = 5; i < 30; i++){
            if (accion[i]=='.'){
                break;
            }else{
                nombre[cont]=accion[i];
                cont++;  
            }
        }
        ofstream outFile;
        string archivo="";
        archivo=nombre;
        archivos+=nombre;
        archivo+=".txt";
	        outFile.open(archivo,std::ios::app);
	        outFile<<""<<endl;
            outFile.close();
    }
    
    if (accion[0]=='w'&&accion[1]=='r'&&accion[2]=='i'&&accion[3]=='t'&&accion[4]=='e'){
        //printw(" mensakeee");
        char nombre[256];
        int cont=0;
        int cont2=0;
        for (int i = 6; i < 256; i++){
            if (accion[i]=='.'){
                cont2=i+5;
                break;
            }else{
                nombre[cont]=accion[i];
                cont++;  
            }
        } 
        string mensaje="";
        printw("archivos ",archivos);
        if (archivos.find(nombre)==true){
           printw("lo encontro");
            for (int i = cont2; i < 256; i++){
                mensaje+=accion[i];
            }
            string archivo="";
            archivo=nombre;
            archivo+=".txt";

             ofstream outFile;
            outFile.open(archivo,std::ios::app);
	        outFile<<mensaje<<" "<<endl;
            printw("mensaje");
            printw("%s",mensaje);
            outFile.close();
            
        }
        
        
        
    }
    
    

    refresh();
}
    
    endwin();
    return 0;
}
