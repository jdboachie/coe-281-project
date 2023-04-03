int save_game(int GAME_STATE, char profile_name)
{
    FILE *fp;
    char filename[20];
    sprintf(filename, "%s.dat", profile_name);
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error: Could not open save file.");
        return 1;
    }
    fprintf(fp, "%d", GAME_STATE);
    fclose(fp);
    return 0;
}
