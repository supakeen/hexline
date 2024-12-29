#ifndef CMAP_H
#define CMAP_H

#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define DB 0xFF00

/*
 *         ._  ___________  _.
 *         | \ \____0____/ / |
 *         | |._    _    _.| |
 *         | || \  | |  / || |
 *         |5| \H\ |J| /K/ |1|
 *         | |  \_\|_|/_/  | |
 *         |_| ____   ____ |_|
 *          _ < 6  > < 7  > _
 *         | |   ._._._.   | |
 *         | |  / /| |\ \  | |
 *         |4| /N/ |M| \L\ |2|
 *         | ||_/  |_|  \_|| |
 *         | | ___________ | |   __
 *         |/ /_____3_____\ \|  (Dp)
 */

uint16_t *cmap[CHAR_MAX] = {
    // Control
    NULL,  // 0, NULL
    NULL,  // 1, Start of Heading
    NULL,  // 2, Start of Text
    NULL,  // 3, End of Text
    NULL,  // 4, End of Transmission
    NULL,  // 5, Enquiry
    NULL,  // 6, ACK
    NULL,  // 7, Bell/Alert 
    NULL,  // 8, Backspace
    NULL,  // 9, Horizontal Tab
    NULL,  // 10, Line Feed
    NULL,  // 11, Vertical Tab
    NULL,  // 12, Form Feed
    NULL,  // 13, Carriage Return
    NULL,  // 14, Shift Out
    NULL,  // 15, Shift In
    NULL,  // 16, Data Link Escape
    NULL,  // 17, Device Control One (XOFF)
    NULL,  // 18, Device Control Two
    NULL,  // 19, Device Control Three (XON)
    NULL,  // 20, Device Control Four
    NULL,  // 21, NACK
    NULL,  // 22, Sync Idle
    NULL,  // 23, End of Transmission Block
    NULL,  // 24, Cancel
    NULL,  // 25, End of Medium
    NULL,  // 26, Substitute
    NULL,  // 27, Escape
    NULL,  // 28, File Separator
    NULL,  // 29, Group Separator
    NULL,  // 30, Record Separator
    NULL,  // 31, Unit Separator
    // Alphanumeric
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 32, Space
    NULL,  // 33, Exclamation Mark
    NULL,  // 34, Double Quotes
    NULL,  // 35, Number Sign
    NULL,  // 36, Dollar
    NULL,  // 37, Percent Sign
    NULL,  // 38, Ampersand
    NULL,  // 39, Single Quote
    NULL,  // 40, Paren Open
    NULL,  // 41, Paren Close
    NULL,  // 42, Asterisk
    (uint16_t[16]){  0,  0,  0,  0,  0,  0, DB, DB,  0, DB,  0,  0, DB,  0,  0,  0 },  // 43, Plus
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, DB,  0,  0 },  // 44, Comma
    (uint16_t[16]){  0,  0,  0,  0,  0,  0, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 45, Minus
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, DB,  0 },  // 46, Dot
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0 },  // 47, Slash
    (uint16_t[16]){ DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 48, 0
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 49, 1
    (uint16_t[16]){ DB, DB,  0, DB, DB,  0, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 50, 2
    (uint16_t[16]){ DB, DB, DB, DB,  0,  0, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 51, 3
    (uint16_t[16]){  0, DB, DB,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 52, 4
    (uint16_t[16]){ DB,  0, DB, DB,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 53, 5
    (uint16_t[16]){ DB,  0, DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 54, 6
    (uint16_t[16]){ DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 55, 7
    (uint16_t[16]){ DB, DB, DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 56, 8
    (uint16_t[16]){ DB, DB, DB, DB,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 57, 9
    NULL,  // 58, :
    NULL,  // 59, ;
    NULL,  // 60, <
    NULL,  // 61, =
    NULL,  // 62, >
    NULL,  // 63, ?
    NULL,  // 64, @
    // Letters
    (uint16_t[16]){ DB, DB, DB,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 65, A
    (uint16_t[16]){ DB, DB, DB, DB,  0,  0,  0, DB,  0, DB,  0,  0, DB,  0,  0,  0 },  // 66, B
    (uint16_t[16]){ DB,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 67, C
    (uint16_t[16]){ DB, DB, DB, DB,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 68, D
    (uint16_t[16]){ DB,  0,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 69, E
    (uint16_t[16]){ DB,  0,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 70, F
    (uint16_t[16]){ DB,  0, DB, DB, DB, DB,  0, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 71, G 
    (uint16_t[16]){  0, DB, DB,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 72, H
    (uint16_t[16]){ DB,  0,  0, DB,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 73, I 
    (uint16_t[16]){  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 74, J
    (uint16_t[16]){  0,  0, DB,  0, DB, DB, DB, DB,  0,  0, DB,  0,  0,  0,  0,  0 },  // 75, K 
    (uint16_t[16]){  0,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 76, L
    (uint16_t[16]){  0, DB, DB,  0, DB, DB,  0,  0, DB,  0, DB,  0,  0,  0,  0,  0 },  // 77, M
    (uint16_t[16]){  0, DB, DB,  0, DB, DB,  0,  0, DB,  0,  0, DB,  0,  0,  0,  0 },  // 78, N
    (uint16_t[16]){ DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 79, O
    (uint16_t[16]){ DB, DB,  0,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 80, P
    (uint16_t[16]){ DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0, DB,  0,  0,  0,  0 },  // 81, Q 
    (uint16_t[16]){ DB, DB,  0,  0, DB, DB, DB, DB,  0,  0,  0, DB,  0,  0,  0,  0 },  // 82, R 
    (uint16_t[16]){ DB,  0, DB, DB,  0,  0,  0, DB, DB,  0,  0,  0,  0,  0,  0,  0 },  // 83, S
    (uint16_t[16]){ DB,  0,  0,  0,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 84, T 
    (uint16_t[16]){  0, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 85, U 
    (uint16_t[16]){  0,  0,  0,  0, DB, DB,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0 },  // 86, V
    (uint16_t[16]){  0, DB, DB,  0, DB, DB,  0,  0,  0,  0,  0, DB,  0, DB,  0,  0 },  // 87, W
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0, DB,  0, DB, DB,  0, DB,  0,  0 },  // 88, X
    (uint16_t[16]){  0, DB,  0,  0,  0, DB, DB, DB,  0,  0,  0,  0, DB,  0,  0,  0 },  // 89, Y
    (uint16_t[16]){ DB,  0,  0, DB,  0,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0 },  // 90, Z
    NULL,  // 91, [
    NULL,  // 92, \ 
    NULL,  // 93, ]
    NULL,  // 94, ^
    NULL,  // 95, _
    NULL,  // 96, `
    NULL,  // ?, where does this come from?
    (uint16_t[16]){ DB, DB, DB,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 65, A
    (uint16_t[16]){ DB, DB, DB, DB,  0,  0,  0, DB,  0, DB,  0,  0, DB,  0,  0,  0 },  // 66, B
    (uint16_t[16]){ DB,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 67, C
    (uint16_t[16]){ DB, DB, DB, DB,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 68, D
    (uint16_t[16]){ DB,  0,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 69, E
    (uint16_t[16]){ DB,  0,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 70, F
    (uint16_t[16]){ DB,  0, DB, DB, DB, DB,  0, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 71, G 
    (uint16_t[16]){  0, DB, DB,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 72, H
    (uint16_t[16]){ DB,  0,  0, DB,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 73, I 
    (uint16_t[16]){  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 74, J
    (uint16_t[16]){  0,  0, DB,  0, DB, DB, DB, DB,  0,  0, DB,  0,  0,  0,  0,  0 },  // 75, K 
    (uint16_t[16]){  0,  0,  0, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 76, L
    (uint16_t[16]){  0, DB, DB,  0, DB, DB,  0,  0, DB,  0, DB,  0,  0,  0,  0,  0 },  // 77, M
    (uint16_t[16]){  0, DB, DB,  0, DB, DB,  0,  0, DB,  0,  0, DB,  0,  0,  0,  0 },  // 78, N
    (uint16_t[16]){ DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 79, O
    (uint16_t[16]){ DB, DB,  0,  0, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0 },  // 80, P
    (uint16_t[16]){ DB, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0, DB,  0,  0,  0,  0 },  // 81, Q 
    (uint16_t[16]){ DB, DB,  0,  0, DB, DB, DB, DB,  0,  0,  0, DB,  0,  0,  0,  0 },  // 82, R 
    (uint16_t[16]){ DB,  0, DB, DB,  0,  0,  0, DB, DB,  0,  0,  0,  0,  0,  0,  0 },  // 83, S
    (uint16_t[16]){ DB,  0,  0,  0,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0,  0 },  // 84, T 
    (uint16_t[16]){  0, DB, DB, DB, DB, DB,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },  // 85, U 
    (uint16_t[16]){  0,  0,  0,  0, DB, DB,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0 },  // 86, V
    (uint16_t[16]){  0, DB, DB,  0, DB, DB,  0,  0,  0,  0,  0, DB,  0, DB,  0,  0 },  // 87, W
    (uint16_t[16]){  0,  0,  0,  0,  0,  0,  0,  0, DB,  0, DB, DB,  0, DB,  0,  0 },  // 88, X
    (uint16_t[16]){  0, DB,  0,  0,  0, DB, DB, DB,  0,  0,  0,  0, DB,  0,  0,  0 },  // 89, Y
    (uint16_t[16]){ DB,  0,  0, DB,  0,  0,  0,  0,  0,  0, DB,  0,  0, DB,  0,  0 },  // 90, Z
 
    NULL,  // 123, {
    NULL,  // 124, |
    NULL,  // 125, }
    NULL,  // 126, ~
    NULL,  // 127, DEL
    // > 127, unsupported
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
    NULL,  // > 127
};

#endif
