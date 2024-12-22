#ifndef AREA_H
#define AREA_H

#define AREA_CHAR_C 32  // there are 32 characters per area

#define AREA_SEG_C 16   // and each character has 16 segments
#define AREA_SEG_W 2    // and each segment has a width of 2 bytes (16-bits)

// giving us a total width of CHAR_C * SEG_C * SEG_W plus
// the end of frame marker (4)
#define AREA_SIZE AREA_CHAR_C * AREA_SEG_C * AREA_SEG_W

void area_init(void);
void area_clear(char*);
void area_draw(char*, char *);

void area_text_ltr(char*, char *);
void area_text_ltr_at(char*, char *, int);

void area_fade(char*);

#endif