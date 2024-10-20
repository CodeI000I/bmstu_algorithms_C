

void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j)){
            for (int iter = 0; iter < nel; iter ++){
                for( int pass = 0; pass < nel - 1; pass ++){
                    if (compare(pass, pass+1) == 1){
                        swap(pass, pass+1);
                    } else if (compare(nel - (pass + 2), nel - (pass + 1)) == 1){
                        swap(nel - (pass + 2), nel - (pass + 1));
                    }
                }
            }
}

