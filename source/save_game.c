int save_game(int GAME_STATE)
{
    FILE *fp;
    char filename[100];
    char profile_name[50];
    sprintf(filename, "%s.dat", profile_name);
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error: Could not open save game.");
        return 1;
    }
    fprintf(fp, "%d", GAME_STATE);
    fclose(fp);
    return 0;
}
