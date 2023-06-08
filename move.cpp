    #include <iostream>
    #include <conio.h>
    #include <windows.h>
    using namespace std;

        int main(){
            
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            if ( h==INVALID_HANDLE_VALUE ){
                cout << "Error in CreateConsoleScreenBuffer(), exited"<<endl;
                return 1;
            }
            AttachConsole(ATTACH_PARENT_PROCESS);

            _COORD coord;
            coord.X = 1;
            coord.Y = 1;

            char ch;
            DWORD numberOfCharsWritten;
            do{

                ch = getch();

                if ( !SetConsoleCursorPosition(h, coord) ){
                    cout << "Error in SetConsoleCursorPosition(), exited"<<endl;
                    return 1;
                }
                if ( ! WriteConsoleA(h, " ", 1, &numberOfCharsWritten, NULL) ){
                    cout << "Error in WriteConsole(), exited"<<endl;
                    return 1;
                }

                switch (ch){
                    case 'a':
                        if(coord.X>0)
                            coord.X--;
                        break;
                    case 'd':
                        if (coord.X<50)
                            coord.X++;
                        break; 
                    case 'w':
                        if(coord.Y>0)
                            coord.Y--;
                        break;
                    case 's':
                        if (coord.Y<20)
                            coord.Y++;
                        break; 
                }
                
                if ( !SetConsoleCursorPosition(h, coord) ){
                    cout << "Error in SetConsoleCursorPosition(), exited"<<endl;
                    return 1;
                }
                if ( ! WriteConsoleA(h, "o", 1, &numberOfCharsWritten, NULL) ){
                    cout << "Error in WriteConsole(), exited"<<endl;
                    return 1;
                }

            } while (ch!='q');
            
            return 0; 
        }