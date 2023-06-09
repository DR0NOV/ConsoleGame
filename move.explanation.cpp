    #include <iostream>
    #include <conio.h>
    #include <windows.h>
    using namespace std;

        int main(){
            
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		//  GetStdHandle предоставляет механизм получения связанных с процессом дескрипторов стандартного вывода
            if ( h==INVALID_HANDLE_VALUE ){
                cout << "Error in CreateConsoleScreenBuffer(), exited"<<endl;
                return 1;
            }
            AttachConsole(ATTACH_PARENT_PROCESS);
		// AttachConsole присоединяет вызывающий процесс к консоли

            _COORD coord;
            coord.X = 1;
            coord.Y = 1;

            char ch;
            DWORD numberOfCharsWritten;
            do{

                ch = getch();
		// getch нужна для чтения символа с клавиатуры
		// печатает пробел на старом месте
                if ( !SetConsoleCursorPosition(h, coord) )
			//SetConsoleCursorPosition устанавливает персонажа на конкретную позицию
		{
                    cout << "Error in SetConsoleCursorPosition(), exited"<<endl;
                    return 1;
                }
                if ( ! WriteConsoleA(h, " ", 1, &numberOfCharsWritten, NULL) )
		// WriteConsoleA ставит игрока в текущем положении курсора
		{
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
                // печатает "o" на новом месте
                if ( !SetConsoleCursorPosition(h, coord) ){
                    cout << "Error in SetConsoleCursorPosition(), exited"<<endl;
                    return 1;
                }
                if ( ! WriteConsoleA(h, "o", 1, &numberOfCharsWritten, NULL) ){
                    cout << "Error in WriteConsole(), exited"<<endl;
                    return 1;
                }
		// q выход
            } while (ch!='q');
            
            return 0; 
        }