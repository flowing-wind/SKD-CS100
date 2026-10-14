/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
    int n;
    scanf("%d", &n);

    int reg[7] = {0};
    for (int i = 0; i < n; i++)
    {
        unsigned int inst;
        unsigned int opcode, r1, r2, imm;
        scanf("%x", &inst);

        opcode = (inst >> 13) & 0x7u;
        r1 = (inst >> 10) & 0x7u;
        r2 = (inst >> 7) & 0x7u;
        imm = inst & 0x7Fu;

        if (r1 == 0 && opcode != 0x5)
        {
            continue;
        }

        switch (opcode)
        {
        case 0x0: // add
            reg[r1] += reg[r2];
            break;

        case 0x1: // sub
            reg[r1] -= reg[r2];
            break;

        case 0x2: // mul
            reg[r1] *= reg[r2];
            break;

        case 0x3: // div
            reg[r1] /= reg[r2];
            break;

        case 0x4: // let
            reg[r1] = imm;
            break;

        case 0x5: // print
            printf("x%u = %u\n", r1, reg[r1]);
            break;

        default:
            break;
        }
    }

    return 0;
}
