## (1)使用する構造体、列挙体

### ➀構造体:editorConfig
```c
struct editorConfig {
     /* Cursor x and y position in characters */
    int cx,cy;  
     /* Offset of row displayed. */
    int rowoff;  
    /* Offset of column displayed. */
    int coloff; 
    /* Number of rows that we can show */
    int screenrows; 
     /* Number of cols that we can show */
    int screencols;
     /* Number of rows */
    int numrows;
    /* Is terminal raw mode enabled? */
    int rawmode;
    /* Rows */
    erow *row;
    /* File modified but not saved. */
    int dirty;      
    /* 開いたファイルの名前。editorOpen()で設定する。*/
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
};
/*E.numrowsなどの形で使うことが出来る。*/
static struct editorConfig E;
```

### ➁列挙体:KEY_ACTION
```c
enum KEY_ACTION{
        KEY_NULL = 0,       /* NULL */
        CTRL_C = 3,         /* Ctrl-c */
        CTRL_D = 4,         /* Ctrl-d */
        CTRL_F = 6,         /* Ctrl-f */
        CTRL_H = 8,         /* Ctrl-h */
        TAB = 9,            /* Tab */
        CTRL_L = 12,        /* Ctrl+l */
        ENTER = 13,         /* Enter */
        CTRL_Q = 17,        /* Ctrl-q */
        CTRL_S = 19,        /* Ctrl-s */
        CTRL_U = 21,        /* Ctrl-u */
        ESC = 27,           /* Escape */
        BACKSPACE =  127,   /* Backspace */
        /* The following are just soft codes, not really reported by the
         * terminal directly. */
        ARROW_LEFT = 1000,
        ARROW_RIGHT,
        ARROW_UP,
        ARROW_DOWN,
        DEL_KEY,
        HOME_KEY,
        END_KEY,
        PAGE_UP,
        PAGE_DOWN
};

```

## (2)main関数

```c
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr,"Usage: kilo <filename>\n");
        exit(1);
    }

    initEditor();
    editorOpen(argv[1]);/**/
    enableRawMode(STDIN_FILENO);
    editorSetStatusMessage(
        "HELP: Ctrl-Q = quit");
    while(1) {
        editorRefreshScreen();
        editorProcessKeypress(STDIN_FILENO);
    }
    return 0;
}

```
## (3)editorOpen関数
```c
int editorOpen(char *filename) {
    FILE *fp;

    E.dirty = 0;
    
    /*ファイルの名前を設定している。*/
    free(E.filename);
    size_t fnlen = strlen(filename)+1;
    E.filename = malloc(fnlen);
    memcpy(E.filename,filename,fnlen);

    fp = fopen(filename,"r");
    
    if (!fp) {
        if (errno != ENOENT) {
            perror("Opening file");
            exit(1);
        }
        return 1;
    }

    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while((linelen = getline(&line,&linecap,fp)) != -1) {
        if (linelen && (line[linelen-1] == '\n' || line[linelen-1] == '\r'))
            line[--linelen] = '\0';
        /*ファイルの内容をセットしている*/
        editorInsertRow(E.numrows,line,linelen);
    }
    free(line);
    fclose(fp);
    E.dirty = 0;
    return 0;
}
```
## (4)editorInsertRow
editorInsertRowは、(3)editorOpen関数で読み込んだ行を書き込む関数
```c
void editorInsertRow(int at, char *s, size_t len) {
    if (at > E.numrows) return;
    E.row = realloc(E.row,sizeof(erow)*(E.numrows+1));
    if (at != E.numrows) {
        memmove(E.row+at+1,E.row+at,sizeof(E.row[0])*(E.numrows-at));
        for (int j = at+1; j <= E.numrows; j++) E.row[j].idx++;
    }
    E.row[at].size = len;
    E.row[at].chars = malloc(len+1);
    memcpy(E.row[at].chars,s,len+1);
    E.row[at].hl = NULL;
    E.row[at].hl_oc = 0;
    E.row[at].render = NULL;
    E.row[at].rsize = 0;
    E.row[at].idx = at;
    editorUpdateRow(E.row+at);
    E.numrows++;
    E.dirty++;
}
```
## (5)initEditor

構造体```E```を初期化している。
```c
void initEditor(void) {
    E.cx = 0;
    E.cy = 0;
    E.rowoff = 0;
    E.coloff = 0;
    E.numrows = 0;
    E.row = NULL;
    E.dirty = 0;
    E.filename = NULL;
    updateWindowSize();
}
```
