

    #include <stdlib.h>
    #include <stdio.h>
    #include <assert.h>

    # ifndef TYPE
    # define TYPE int
    # endif

    //global to keep track of total additions
    int count = 0;

    // global for units of time before each reassignment
    int segmentTime = 0;


    struct DynArr
    {
        TYPE *data;
        /* pointer to the data array */
        int size;
        /* Number of elements in the array */
        int capacity;
        /* capacity ofthe array */
    };

    void initDynArr(struct DynArr *v, int capacity)
    {
        v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
       // v->data = malloc(sizeof(TYPE) * capacity);
        assert(v->data != 0);
        v->size = 0;
        v->capacity = capacity;
       // memset(v->data, 0, capacity * sizeof(TYPE) );
    }

    void freeDynArr(struct DynArr *v)
    {
        if(v->data != 0)
        {
            free(v->data);
        /* free the space on the heap */
            v->data = 0;
        /* make it point to null */
        }
        v->size = 0;
        v->capacity = 0;
    }

    int sizeDynArr( struct DynArr *v)
    {
        return v->size;
    }

    void _setCapacityDynArr(struct DynArr *v, int newCap){
        // declare temp array and initalize
        TYPE *temporaryArray = (TYPE *)malloc(sizeof(TYPE)*newCap);

        //copy the elements of v into temp
        int i;
        for(i = 0; i < v->size; ++i){
            temporaryArray[i] = v->data[i];
          //  segmentTime++;
        }

        // free old array
        free(v->data);
        assert(v != 0);

        //set v to address of temp
        v->data = temporaryArray;
        //segmentTime++;

        v->capacity = newCap;
    }

    void addDynArr(struct DynArr *v, TYPE val)
    {

        /* Check to see if a resize is necessary */
        if(v->size >= v->capacity){
            printf("Segment Time: %d Values added: %d Average: %f\n",
                   segmentTime, count, (float)segmentTime/(float)count);
            _setCapacityDynArr(v, 2 * v->capacity);
        }
        v->data[v->size] = val;
        v->size++;
        count += 1;
        segmentTime += 1;
    }


    int main(){

        struct DynArr data;

        initDynArr(&data, 1);

        for(int i = 0; i < 2300000; ++i){
            addDynArr(&data, i);
        }

        freeDynArr(&data);
    }

