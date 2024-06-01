#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <wallhavenapi.h>

static struct option long_options[] = {
    {"config", required_argument, 0, 'c'},
    {"help", no_argument, 0, 'h'},
    {"api-key", required_argument, 0, 'k'},
    {0, 0, 0, 0}
};

void print_help() {
    printf(
        "NAME\n"
        "\twwd - Wallhaven Wallpaper Downloader\n"
        "USAGE:\n"
        "\twwd [OPTIONS] [ARGS] [TAGS]\n"
        "OPTIONS:\n"
        "\t-c <file> | --config <file>\t\t\t\tConfig file to use\n"
        "\t-k <key> | --api-key <key>\t\t\t\tWallhaven API key to use\n"
        "\t-h | --help \t\t\t\t\t\tAPI key to use\n"
    );
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    FILE *cf = NULL;
    char *api_key = NULL;

    while (1) {
        int option_index = 0;

        int c = getopt_long(argc, argv, "c:k:h", long_options, &option_index);

        if (c == -1) break;

        switch(c) {
            case 'h':
                print_help();
                break;
            case 'c':
                cf = fopen(optarg, "r");
                if (!cf) {
                    printf("Couldn't open the file %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
#ifdef DEBUG
                char ch;
                while ((ch = fgetc(cf)) != EOF) printf("%c", ch);
#endif
                break;
            case 'k':
                api_key = optarg;
#ifdef DEBUG
                printf("api key = %s\n", api_key);
#endif
                break;
            case '?':
                break;
            default:
                printf("?? getopt returned character code 0%o ?? \n", c);
        }
    }

    printf("Tags are: ");
    while (optind < argc)
        printf("%s ", argv[optind++]);
    printf("\n");
}
