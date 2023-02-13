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

Song *removeSong(Playlist *playlist, int id)
{
    Song *removedSong = playlist->head;
    while ((removedSong != NULL) && (removedSong->id != id))
    {
        removedSong = removedSong->next;
    }

    if (removedSong == NULL)
    {
        return NULL;
    }

    else if ((removedSong == playlist->head) && (removedSong == playlist->tail))
    {
        playlist->head = NULL;
        playlist->tail = NULL;
    }

    else if (removedSong == playlist->head)
    {
        removedSong->next->prev = NULL;
        playlist->head = removedSong->next;
    }

    else if (removedSong == playlist->tail)
    {
        removedSong->prev->next = NULL;
        playlist->tail = removedSong->prev;
    }
    else
    {
        Song *prevSong = removedSong->prev;
        Song *nextSong = removedSong->next;
        prevSong->next = nextSong;
        nextSong->prev = prevSong;
    }

    removedSong->next = NULL;
    removedSong->prev = NULL;
    return removedSong;
}

Song *changeNextSong(Playlist *playlist, int id)

{

    Song *currSong = playlist->currentSong;

    if (currSong->id == id)
    {
        return NULL;
    }

    if (currSong == NULL)
    {
        Song *nextToBeSong = addSong(playlist, id);
        return nextToBeSong;
    }

    Song *nextToBeSong = removeSong(playlist, id);
    Song *nextSong = playlist->currentSong->next;

    if (nextToBeSong == NULL)
    {
        nextToBeSong = createSong(id);
    }

    nextToBeSong->prev = currSong;
    nextToBeSong->next = nextSong;
    currSong->next = nextToBeSong;
    if (nextSong != NULL)
    {
        nextSong->prev = nextToBeSong;
    }

    return nextToBeSong;
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
        else if (operation == 6)
        {
            int id;
            scanf("%d", &id);
            changeNextSong(playlist, id);
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