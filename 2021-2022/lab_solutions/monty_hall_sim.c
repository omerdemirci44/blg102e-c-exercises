// monty_hall_sim.c
#include <stdio.h>
#include <stdlib.h>
static int urand(int n){ return rand()%n; }
int main(void){ int N; unsigned int seed=42; if (scanf("%d",&N)!=1) return 0; scanf("%u",&seed); srand(seed);
    int stay=0, sw=0; for(int i=0;i<N;++i){ int prize=urand(3), pick=urand(3), open;
        for(;;){ open=urand(3); if (open!=prize && open!=pick) break; }
        if (pick==prize) ++stay; int sp=3-pick-open; if (sp==prize) ++sw; }
    printf("stay wins: %d\nswitch wins: %d\n", stay, sw); return 0; }
