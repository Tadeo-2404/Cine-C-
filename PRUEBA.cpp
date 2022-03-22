// // #include <iostream>
// // using namespace std;

// // int main()
// // {
// //     {

// //         string myString = "11.60";
// //         string newString = "ho";
// //         newString[0] = myString[3]; // h = 8
// //         newString[1] = myString[4]; // o = 9
// //         string condicionS = "S";
// //         condicionS[0] = myString[3];
// //         int condicion = stoi(condicionS);
// //         cout << "Hora inicial: " << myString << endl;

// //         if (condicion >= 6)
// //         {
// //             int auxConversor, minutosSobrantes;
// //             string nuevaHora = "ec";
// //             nuevaHora[0] = myString[0];
// //             nuevaHora[1] = myString[1];

// //             auxConversor = stoi(newString);
// //             minutosSobrantes = auxConversor - 60;
// //             auxConversor = stoi(nuevaHora);
// //             nuevaHora = to_string(++auxConversor);

// //             myString[0] = nuevaHora[0];
// //             myString[1] = nuevaHora[1];
// //             newString = to_string(minutosSobrantes);
// //             myString[3] = newString[0];
// //             myString[4] = newString[1];
// //         }
// //         cout << "Hora final: " << myString << endl; // "18.89"
// //     }
// // }


//  if(getSalaID - 1 == 1)
//       {
        
//         SalaGrande &salaGrande = arregloSalaGrande[1];
//         cout << "Peli: " <<endl;
//         salaGrande.mostrarPelicula();
//         // SalaGrande.mostrarAsientos();
//         // asiento = SalaGrande.escogerAsiento();
//         // cout << "Tu asiento escogido es..." << asiento <<endl;
//         // Pelicula pelicudaEscogida = SalaGrande.mostrarPeliEscogida(getPeliID);
//         // cout << "Nombre:" << pelicudaEscogida.getNombre() <<endl;
//         // cout << "Horario:" << pelicudaEscogida.getHorario() <<endl;
//         // cout << "Sala N.-" << getSalaID <<endl;

//       } else if(getSalaID - 1 == 0) {

//         SalaGrande &salaGrande = arregloSalaGrande[0];
//         cout << "Peli: " <<endl;
//         salaGrande.mostrarPelicula();
//         // SalaGrande.mostrarAsientos();
//         // asiento = SalaGrande.escogerAsiento();
//         // cout << "Tu asiento escogido es..." << asiento <<endl;
//         // Pelicula pelicudaEscogida = SalaGrande.mostrarPeliEscogida(getPeliID);
//         // cout << "Nombre:" << pelicudaEscogida.getNombre() <<endl;
//         // cout << "Horario:" << pelicudaEscogida.getHorario() <<endl;
//         // cout << "Sala N.-" << getSalaID <<endl;

//       } else {

//         SalaMediana &salaMediana = arregloSalaMedian[getSalaID - 1];
//         cout << "Peli: " <<endl;
//         salaMediana.mostrarPelicula();
//         // SalaMediana.mostrarAsientos();
//         // asiento = SalaMediana.escogerAsiento();
//         // cout << "Tu asiento escogido es..." << asiento <<endl;
//         // Pelicula pelicudaEscogida = SalaMediana.mostrarPeliEscogida(getPeliID);
//         // cout << "Nombre:" << pelicudaEscogida.getNombre() <<endl;
//         // cout << "Horario:" << pelicudaEscogida.getHorario() <<endl;
//         // cout << "Sala N.-" << getSalaID <<endl;

//       }
