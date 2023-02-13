#include <stdio.h>
#include <stdlib.h>

struct Song
{
    int id;
    struct Song *next;
    struct Song *prev;
};

typedef struct Song Song;

struct Playlist
{
    Song *head;
    Song *tail;
    Song *currentSong;
};

typedef struct Playlist Playlist;

Song *createSong(int id)
{
    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->id = id;
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

Playlist *createPlaylist()
{
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    playlist->head = NULL;
    playlist->tail = NULL;
    playlist->currentSong = NULL;
    return playlist;
}

Song *addSong(Playlist *playlist, int id)
{
    Song *newSong = createSong(id);
    if (playlist->head == NULL)
    {
        playlist->head = newSong;
        playlist->tail = newSong;
        playlist->currentSong = newSong;
    }
    else
    {
        playlist->tail->next = newSong;
        newSong->prev = playlist->tail;
        playlist->tail = newSong;
    }

    return newSong;
}

Song *currentlyPlayingSong(Playlist *playlist)
{
    return playlist->currentSong;
}

Song *playNextSong(Playlist *playlist)
{
    if (playlist->currentSong == NULL)
    {
        return NULL;
    }

    Song *nextSong = playlist->currentSong->next;
    if (nextSong != NULL)
    {
        playlist->currentSong = nextSong;
    }

    return playlist->currentSong;
}

Song *playPrevSong(Playlist *playlist)
{
    if (playlist->currentSong == NULL)
    {
        return NULL;
    }

    Song *prevSong = playlist->currentSong->prev;
    if (prevSong != NULL)
    {
        playlist->currentSong = prevSong;
    }

    return playlist->currentSong;
}

Playlist *readPlaylist()
{

    Playlist *playlist = createPlaylist();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        addSong(playlist, id);
    }

    return playlist;
}

void Play(Playlist *playlist)
{
    int operation = -1;

    while (operation != 5)
    {
        scanf("%d", &operation);

        if (operation == 1)
        {
            int id;
            scanf("%d", &id);
            addSong(playlist, id);
        }
        else if (operation == 2)
        {
            Song *currentSong = playlist->currentSong;
            if (currentSong == NULL)
            {
                printf("No song is being played\n");
            }
            else
            {
                printf("Currently playing song: %d\n", currentSong->id);
            }
        }
        else if (operation == 3)
        {
            playNextSong(playlist);
        }
        else if (operation == 4)
        {
            playPrevSong(playlist);
        }
        else if (operation == 5)
        {
            break;
        }
        else
        {
            printf("Please enter a valid operation\n\n");
        }
    }

    return;
}

int main()
{
    Playlist *playlist1 = readPlaylist();
    Play(playlist1);
    return 0;
}