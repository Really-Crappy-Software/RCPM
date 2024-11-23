#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
//   _ __ ___ ___
//  | '__/ __/ __|
//  | | | (__\__ \_
//  |_|  \___|___(_) Software done worse.
//
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main ( int argc, char* argv[] ) {
	CURL *handle;
	handle = curl_easy_init();
    FILE *fp;
    char locateballs[100] = "/etc/rcpm/";
    char blorb[100] = "http://127.0.0.1/";
    CURLcode res;
    char $PACKAGE[100];
    if (strcmp(argv[1], "-h") == 0) {
        printf("SYNTAX: rcpm (-i, -h, -v, -r) <PACKAGE>\n -i: Installs a package\n -r: Removes a Package\n -h: Displays this menu\n -v: Displays the version of the program (not the package)\n if you encounter any bugs please report it on Github.\n");
    } else if (strcmp(argv[1], "-v") == 0) {
        printf("Really Crap Package Manager Ver 0.01\n");
    } else if (strcmp(argv[1], "-i") == 0) {
        printf("Installing %s\n", argv[2]);
	if (handle) {
	fp = fopen("foo.tar", "w");
	strcat(argv[2], ".tar");
	strcat(blorb, argv[2]);
        curl_easy_setopt(handle, CURLOPT_URL, blorb);
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, fp);
	res = curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	fclose(fp);
      system("tar -xf foo.tar");
      chdir("foo");
      system("./make.sh");
      chdir("..");
      system("rm -r foo foo.tar");
	}
    }  else if (strcmp(argv[1], "-r") == 0) {
        strcat(locateballs, argv[2]);
	system(locateballs);
    } else {
        printf("SYNTAX: rcpm (-i, -h, -v, -r) <PACKAGE>\n -i (or --install): Installs a package\n -r(or --remove): Removes a Package\n -h(or --help): Displays this menu\n -v(or --version): Displays the version of the program (not the package)\n if you encounter any bugs please report it on Github.\n");
    }
}
