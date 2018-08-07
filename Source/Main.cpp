
// Include the only file
#include "CustomUI.h"

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // notice this! you need it!
#include <time.h>

#define DESTINATION_FOLDER "/sxos/"
#define SOURCE_FOLDER "/switch/moddy/"
int selected = 0;
// Create two pages with their names
static CustomUI::Page page1("General");
static CustomUI::Page page2("Mods");


 //the colors
 int selectedOption = 0;
 int text1color1 = 255;
 int text2color1 = 255;
 int text3color1 = 255;

  int text1color2 = 255;
 int text2color2 = 255;
 int text3color2 = 255;

  int text1color3 = 255;
 int text2color3 = 255;
 int text3color3 = 255;
// Static var
static string text1 = "Mods";
static string textx = "Log";
static string selectedbool = "no";
static string selectedText = "";
static string ModsText1 = "Uninstall All";
static string ModsText2 = "Zelda Skin";
static string ModsText3 = "Waluigi skin";


// Rendering functions

int file_exist (char *filename)
{
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}


void page1render()
{
    page1.renderText(text1, 30, 30, { 255, 255, 255, 255 }, 50);
    page1.renderText(ModsText1, 30, 100, { text1color1, text1color2, text1color3, 255 }, 20);
    page1.renderText(ModsText2, 30, 125, { text2color1, text2color2, text2color3, 255 }, 20);
    page1.renderText(ModsText3, 30, 150, { text3color1, text3color2, text3color3, 255 }, 20);
    page1.renderText(textx, 30, 190, { 255, 255, 255, 255 }, 20);
}

void page2render()
{
    page1.renderText("General", 30, 30, { 255, 255, 255, 50 }, 50);
    page1.renderText("Use this tool on your own risk. if you install multiple Skin mods at the same time,\n you maybe break your game. So make sure to uninstall the Skin you've previously\n installed, before installed another skinpack.\n Some skinpacks, include audio files for the voice, and some dont. \nSwitch between option in the mods tab using the arrow keys. apply them with A.\n\nDon't have the app opened for too long while not using it. it might make your\n switch freeze.\nAfter installing a mod, you mayb", 30, 100, { 255, 255, 255, 255 }, 20);
}



void installZeldaMod()
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;
    
    char src_folder[1024];
    char dest_folder[1024];
    
    
    if((dp = opendir("/switch/moddy/zeldaskinpack/")) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", "/switch/moddy/zeldaskinpack/");
        return;
    }
    chdir("/switch/moddy/zeldaskinpack/");
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        
        if(!S_ISDIR(statbuf.st_mode)) \
        {
            sprintf(src_folder,"%s%s", "/switch/moddy/zeldaskinpack/",entry->d_name);
            sprintf(dest_folder,"%s%s", "/sxos/titles/01007EF00011E000/",entry->d_name);
            printf("%s----------------%s\n",entry->d_name,dest_folder);
            rename(src_folder, dest_folder);
        }
    }
    chdir("..");
    closedir(dp);
    return 0;
    exit(0);
}



void InstallWaluigiMod()
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;
    
    char src_folder[1024];
    char dest_folder[1024];
    
    
    if((dp = opendir("/switch/moddy/waluigi_skinpack/")) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", "/switch/moddy/waluigi_skinpack/");
        return;
    }
    chdir("/switch/moddy/zeldaskinpack/");
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        
        if(!S_ISDIR(statbuf.st_mode)) \
        {
            sprintf(src_folder,"%s%s", "/switch/moddy/waluigi_skinpack/",entry->d_name);
            sprintf(dest_folder,"%s%s", "/sxos/titles/01007EF00011E000/",entry->d_name);
            printf("%s----------------%s\n",entry->d_name,dest_folder);
            rename(src_folder, dest_folder);
        }
    }
    chdir("..");
    closedir(dp);
    return 0;
    exit(0);
}

void RecoverZeldaSkinpack(){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;
    
    char src_folder[1024];
    char dest_folder[1024];
    
    
    if((dp = opendir("/sxos/titles/01007EF00011E000/")) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", "/sxos/titles/01007EF00011E000/");
        return;
    }
    chdir("/sxos/titles/01007EF00011E000/");
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        
        if(!S_ISDIR(statbuf.st_mode)) \
        {
            sprintf(src_folder,"%s%s", "/sxos/titles/01007EF00011E000/",entry->d_name);
            sprintf(dest_folder,"%s%s", "/switch/moddy/zeldaskinpack/",entry->d_name);
            printf("%s----------------%s\n",entry->d_name,dest_folder);
            rename(src_folder, dest_folder);
        }
    }
    chdir("..");
    closedir(dp);
    
    
}


void RecoverWaluigiSkinpack(){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;
    
    char src_folder[1024];
    char dest_folder[1024];
    
    
    if((dp = opendir("/sxos/titles/01007EF00011E000/")) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", "/sxos/titles/01007EF00011E000/");
        return;
    }
    chdir("/sxos/titles/01007EF00011E000/");
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        
        if(!S_ISDIR(statbuf.st_mode)) \
        {
            sprintf(src_folder,"%s%s", "/sxos/titles/01007EF00011E000/",entry->d_name);
            sprintf(dest_folder,"%s%s", "/switch/moddy/waluigi_skinpack/",entry->d_name);
            printf("%s----------------%s\n",entry->d_name,dest_folder);
            rename(src_folder, dest_folder);
        }
    }
    chdir("..");
    closedir(dp);
    
    
}


void deleteAllMods(){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct tm      *tm;
    
    char src_folder[1024];
    char dest_folder[1024];
    
    
    if((dp = opendir("/sxos/titles/01007EF00011E000/")) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", "/sxos/titles/01007EF00011E000/");
        return;
    }
    chdir("/sxos/titles/01007EF00011E000/");
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        
        if(!S_ISDIR(statbuf.st_mode)) \
        {
            sprintf(src_folder,"%s%s", "/sxos/titles/01007EF00011E000/",entry->d_name);
            sprintf(dest_folder,"%s%s", "/switch/moddy/old_mods_deleted/",entry->d_name);
            printf("%s----------------%s\n",entry->d_name,dest_folder);
            rename(src_folder, dest_folder);
        }
    }
    chdir("..");
    closedir(dp);
    return 0;
    exit(0);
}

void downloadMod(int option){
    if(option == 1){
        chdir("/switch/moddy/");
        DIR* dir = opendir("old_mods_deleted");
        if (dir)
        {
            closedir(dir);
        }
        else if (ENOENT == errno)
        {
            mkdir("old_mods_deleted", 0777);
        }
        textx += "\nDeleting all mods";
        if (file_exist ("/sxos/titles/01007EF00011E000/zelda_skinpack.txt")){
            RecoverZeldaSkinpack();
            textx += "\nrecovered the zelda skinpack";
            textx += "\ndone";
        }else if(file_exist ("/sxos/titles/01007EF00011E000/waluigi_skinpack.txt")){
            RecoverWaluigiSkinpack();
            textx += "\nrecovered the waluigi skinpack";
            textx += "\ndone";
        }else{
            deleteAllMods();
            textx += "\nDeleting.... please wait...";
            textx += "\ndone";
        }
        return 0;
    }else if(option == 2){
        textx += "\ninstalling zelda skinpack...";
        if (file_exist ("/sxos/titles/01007EF00011E000/zelda_skinpack.txt"))
        {
            textx += "\nYou have this package installed already!";
        }else{
            installZeldaMod();
            textx += "\nDone!";
        }
    }else if(option == 3){
        textx += "\ninstalling Waluigi skinpack...";
        if (file_exist ("/sxos/titles/01007EF00011E000/waluigi_skinpack.txt"))
        {
            textx += "\nYou have this package installed already!";
        }else{
            InstallWaluigiMod();
            textx += "\nDone!";
        }
    }
}

int main()
{
    chdir("/switch/moddy/");
    DIR* zeldadir = opendir("zeldaskinpack");
    if (zeldadir){
        closedir(zeldadir);
    }
    else if (ENOENT == errno){
        mkdir("zeldaskinpack", 0777);
    }
    
    
    DIR* waluigidir = opendir("waluigi_skinpack");
    if (waluigidir){
        closedir(waluigidir);
    }
    else if (ENOENT == errno){
        mkdir("waluigi_skinpack", 0777);
    }
    
    
    
    // Init libs, with a title, a footer and a theme (you can create your own themes!)
    CustomUI::init("BOTW Modder", "Press plus to exit Press A to select", CustomUI::HorizonDark());

    // Set their rendering functions (what will be called every time the UI renders)
    page1.onRender(page1render);
    page2.onRender(page2render);

    // Add both pages to our UI
    CustomUI::addPage(page1);
    CustomUI::addPage(page2);

    // Main loop starts
    while(appletMainLoop())
    {
        // Every main loop flushGraphics must be called
        CustomUI::flushGraphics();

        // This is the proper way to access input with CustomUI as every loop the keys are updated
        int keysDown = CustomUI::PressedInput;

        // If A is pressed...
        if(keysDown & KEY_A){
            if (selectedOption == 1) {
                textx = "starting...";
                downloadMod(1);

            }else if (selectedOption == 2) {
                textx = "starting...";
                downloadMod(2);
            }else if (selectedOption == 3) {
                textx = "starting...";
                downloadMod(3);
            }
            CustomUI::renderGraphics();
        }
        
        
        if(keysDown & KEY_PLUS){
            break;
        }if(keysDown & KEY_DOWN){
                if(selectedOption == 0){
                    text1color1 = 0;
                    text1color2 = 150;
                    text1color3 = 250;
                    selectedOption++;
                }else if(selectedOption == 1){
                    text1color1 = 255;
                    text1color2 = 255;
                    text1color3 = 255;
                    text2color1 = 0;
                    text2color2 = 150;
                    text2color3 = 250;
                    selectedOption++;
                }else if(selectedOption == 2){
                    text2color1 = 255;
                    text2color2 = 255;
                    text2color3 = 255;
                    text3color1 = 0;
                    text3color2 = 150;
                    text3color3 = 250;
                    selectedOption++;
                }
                

            CustomUI::renderGraphics();

        
        }
        if(keysDown & KEY_UP){
            if(selectedOption == 0){
                text1color1 = 0;
                text1color2 = 150;
                text1color3 = 250;
                selectedOption--;
            }else if(selectedOption == 2){
                text1color1 = 0;
                text1color2 = 150;
                text1color3 = 250;
                text2color1 = 255;
                text2color2 = 255;
                text2color3 = 255;
                selectedOption--;
            }else if(selectedOption == 3){
                text2color1 = 0;
                text2color2 = 150;
                text2color3 = 250;
                text3color1 = 255;
                text3color2 = 255;
                text3color3 = 255;
                selectedOption--;
            }

            CustomUI::renderGraphics();
            }
            // Every time we change something affecting the render we should call this to redraw/re-render the UI
            CustomUI::renderGraphics();

        }
    

    // With exitApp we don't need to call "return 0"
    CustomUI::exitApp();
}
