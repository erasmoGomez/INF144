//
// Created by Erasmo on 6/09/25.
//

#include "AuxiliaryFunctions.hpp"

void open_file_read(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "The file can not be open: " << file_name << endl;
        exit(1);
    }
}

void open_file_write(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "The file can not be open: " << file_name << endl;
        exit(1);
    }
}

int read_time(ifstream& input) {
    //16:30 -> : 16 minutos 30 segundos
    int mm, ss;
    input>>mm;
    input.ignore();
    input>>ss;
    return mm * 60 + ss;
}

void print_line(ofstream &out, int n, char c) {
    for (int i = 0; i < n; ++i) out.put(c);
    out << endl;
}

void print_date(ofstream& output, int date) { //20250904
    int anio = date / 10000;        // 2025
    int mes = (date / 100) % 100;  // 09
    int dia = date % 100;          // 04

    output << right;
    output << setw(2) << setfill('0') << dia;
    output << "/";
    output << setw(2) << setfill('0') << mes;
    output << "/";
    output << setw(4) << anio;

    output << setfill(' ');  // restaurar fill a espacio
}

void print_time(ofstream& output, int s, bool in_days) {
    if(in_days){
        output << setfill('0')<<setw(4) << s / 86400 << ':';
        s = s%86400;
    }
    output << setfill('0') << setw(2) << s / 3600 << ':'
         << setw(2) << (s / 60) % 60 << ':'
         << setw(2) << s % 60;
    output << setfill(' ');
}

int read_date(ifstream & input) {
    int dd, mm, yyyy, date;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void print_title(ofstream &output, const char *title) {
    output << setw((ANCHO_REPORTE + TITULO_SIZE) / 2) << title << endl;
}

void print_headers(ofstream& output, int n_artista) {
    output << "Artist No: "<<n_artista+1<<endl;
    output << setw(ANCHO_REPORTE / N_COLUMNS) << left << "NAME";
    output << setw(ANCHO_REPORTE / N_COLUMNS) << "CODE";
    output << setw(ANCHO_REPORTE / N_COLUMNS) << "DEBUT DATE";
    output << setw(ANCHO_REPORTE / N_COLUMNS) <<"RATING"<< endl;
}

void print_static_values(int codigo, int time, int edad, double sueldo) {
    double new_sueldo = sueldo;
    cout << fixed;
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << codigo;
    cout << setw(ANCHO_REPORTE / N_COLUMNS - 4) << "";
    //print_time(cout, time);
    cout << setw(ANCHO_REPORTE / N_COLUMNS - 4) << edad;
    if (edad > 50) new_sueldo = new_sueldo * 1.025;
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << setprecision(2) << new_sueldo; // 455.45
}

void print_subtitle(ofstream &output, const char *sub_title, double rep_fee_minute) {
    output << setw((ANCHO_REPORTE - SUBTITULO_SIZE) / 2) << "";
    output << sub_title << rep_fee_minute << endl;
    print_line(output, ANCHO_REPORTE, '=');
}

void read_print_name(ifstream& input, ofstream& output, int width){
    int size = 0;
    char c;
    input>>ws;
    while(true){
        c = input.get();
        if(c == ' ') break;
        if (c >= 'a' and c <= 'z') to_upper(c);
        output.put(c);
        size++;
    }
    for(int i=0; i<width-size; i++) output.put(' ');
}

void to_upper(char &c) {
    c =  c - ('a' - 'A');
}

void set_width(ofstream& output, int width, int discount){
    output << setw(width-discount)<<"";
}

void print_data(ofstream & output, char codigo_c, int codigo_int, int start_date, double rating){
    output << codigo_c << codigo_int;
    set_width(output, ANCHO_REPORTE/N_COLUMNS, 5);
    print_date(output, start_date);
    output << setw(ANCHO_REPORTE / N_COLUMNS - 6)<<rating <<endl;
    print_line(output, ANCHO_REPORTE, '-');
}


void read_print_static_data(ifstream &input_artists,
                            int start_date,
                            int &n_artists,
                            char &codigo_c,
                            int &codigo_int,
                            double &rating,
                            ofstream &output){

    input_artists>>ws;
    input_artists>>codigo_c>>codigo_int;
    print_headers(output, n_artists);
    //set_width(output, ANCHO_REPORTE/N_COLUMNS, 4);
    read_print_name(input_artists, output, ANCHO_REPORTE/N_COLUMNS);
    input_artists>>ws;
    input_artists>>rating;
    print_data(output, codigo_c, codigo_int,start_date, rating);
    n_artists++;
}

void get_data_from_plays(ifstream& input_plays, int song_code,
                         char artist_code_c, int artist_code_int,
                         int& play_date, int& n_plays){
    //02/01/2024   A1023   55001   1450000
    input_plays.clear();
    input_plays.seekg(0, ios::beg);
    int artist_code_int_read, song_code_read;
    char artist_code_c_read;
    while(true){
        play_date = read_date(input_plays);
        if(input_plays.eof())break;
        input_plays>>artist_code_c_read>>artist_code_int_read;
        input_plays>>song_code_read;
        if(artist_code_c_read == artist_code_c and artist_code_int_read == artist_code_int
            and song_code_read == song_code){
            input_plays>>n_plays;
            break;
        }
        input_plays.ignore(100, '\n');
    }
    //play_date = 20240302;
    //n_plays = 500;
}

void print_header_data(ofstream& output){
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) << left << "No.";
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) << "DATE";
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) << "CODE";
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) << "TITLE";
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) << left <<"DURATION";
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) << "N PLAYS";
    output << setw(ANCHO_REPORTE / N_COLUMNS_SONGS) <<"TOTAL"<< endl;
}

void search_song_print_name_get_time(ifstream& input_songs, int song_code, int& duration, ofstream& output){
    input_songs.clear();
    input_songs.seekg(0, ios::beg);
    int song_code_read;
    //92110   TakeTwo           2:54
    while(true){
        input_songs>>song_code_read;
        if(input_songs.eof())break;
        if(song_code_read == song_code){
            set_width(output, ANCHO_REPORTE/N_COLUMNS_SONGS, 4);
            read_print_name(input_songs, output, ANCHO_REPORTE/N_COLUMNS_SONGS); // Dato 4
            duration = read_time(input_songs);
            break;
        }
        input_songs.ignore(100, '\n');
    }
}

void read_print_data_per_song(ifstream& input_songs, int play_date, int song_code, int n_plays,
                              int n_songs,
                              ofstream& output, int &total_duration_rep_per_song){
    int duration;
    output<<right<<setfill('0')<<setw(2)<<n_songs+1<<")"; // Dato 1
    output<<setfill(' ');
    set_width(output, ANCHO_REPORTE/N_COLUMNS_SONGS, 9);
    print_date(output, play_date); // Dato 2
    output<<setw(ANCHO_REPORTE/N_COLUMNS_SONGS)<<song_code; // Dato 3
    search_song_print_name_get_time(input_songs,
                                    song_code,
                                    duration,
                                    output);
    print_time(output, duration, false); // Dato 5
    output<<setw(ANCHO_REPORTE/N_COLUMNS_SONGS - 1)<<n_plays; // Dato 6
    set_width(output, ANCHO_REPORTE/N_COLUMNS_SONGS, 7);
    print_time(output, n_plays*duration, true); // Dato 7
    total_duration_rep_per_song += n_plays*duration;
    output<<endl;
}

void print_ranking(ofstream& output, double rating) {
    output << setw(ANCHO_REPORTE/4) << "POPULARITY RANKING: ";
    if (rating >= 4 and rating <= 5)
        output << "HIGH";
    else if (rating >= 3)
        output << "MEDIUM";
    else if (rating >= 2)
        output << "LOW";
    else if (rating >= 1)
        output << "UNSATISFACTORY";
    else
        output << "OUT OF RANGE";
    output << endl;
}

void print_local_stats(ofstream& output, int total_time_rep, double rating, double rep_revenue){
    output<<fixed;
    output<<setprecision(2);
    output<<left<<setw(ANCHO_REPORTE/4)<<"REPLAYS TOTAL TIME: "<< "";
    print_time(output, total_time_rep, true);
    output<<endl;
    print_ranking(output, rating);
    output<<setw(ANCHO_REPORTE/4)<<"REVENUE PER PLAYS: "<< rep_revenue<<endl;

    print_line(output, ANCHO_REPORTE, '=');
}

void read_print_dynamic_data(ifstream& input_artists,
                             ifstream& input_songs,
                             ifstream& input_plays,
                             ofstream& output,
                             char artist_code_c,
                             int artist_code_int,
                             double rating,
                             double rep_fee_minute){
    //55001->90311->92110
    int song_code, play_date, n_plays, n_songs = 0;
    int total_time_rep = 0, total_duration_rep_per_song, total_n_plays = 0;
    double rep_revenue = 0;
    char c;
    output<<"PLAYED SONGS"<<endl;
    print_header_data(output);
    while(true){
        total_duration_rep_per_song = 0;
        input_artists>>song_code;
        //cout<<setw(10)<<song_code;
        get_data_from_plays(input_plays,
                            song_code,
                            artist_code_c,
                            artist_code_int,
                            play_date,
                            n_plays);
        read_print_data_per_song(input_songs,
                                 play_date,
                                 song_code,
                                 n_plays,
                                 n_songs,
                                 output,
                                 total_duration_rep_per_song);
        n_songs++;
        total_time_rep += total_duration_rep_per_song;
        total_n_plays += n_plays;
        c = input_artists.get();
        if(c=='\n')break;
        c = input_artists.get();
    }
    print_line(output, ANCHO_REPORTE, '-');
    rep_revenue = (double)total_n_plays/60.0 * rep_fee_minute;
    print_local_stats(output, total_time_rep, rating, rep_revenue);
}

void read_print_data(ifstream & input_artists,
                     ifstream & input_songs,
                     ifstream & input_plays,
                     ofstream& output,
                     double rep_fee_minute){
    //12/03/2019   A1023   BTS        4.85
    int start_date, codigo_int, n_artists = 0;
    char codigo_c;
    double rating;
    while(true){
        start_date = read_date(input_artists);
        if(input_artists.eof()) break;
        read_print_static_data(input_artists, start_date, n_artists, codigo_c,  codigo_int,  rating,output);
        read_print_dynamic_data(input_artists, input_songs, input_plays, output,
                                codigo_c, codigo_int,  rating, rep_fee_minute);
    }
}

void calculate_report(const char *file_name_artists,
                      const char *file_name_songs,
                      const char *file_name_plays,
                      const char *file_name_output) {
    ifstream input_artists; open_file_read(input_artists, file_name_artists);
    ifstream input_songs; open_file_read(input_songs, file_name_songs);
    ifstream input_plays; open_file_read(input_plays, file_name_plays);
    ofstream output; open_file_write(output, file_name_output);
    double rep_fee_minute;
    print_title(output, "KPOP_MUSIC PLATFORM");
    //cin>>rep_fee_minute;
    rep_fee_minute = 0.85; //Harcode
    print_subtitle(output, "REPLAY FEE PER MINUTE: ", rep_fee_minute);
    read_print_data(input_artists,
                    input_songs,
                    input_plays,
                    output,
                    rep_fee_minute);

}