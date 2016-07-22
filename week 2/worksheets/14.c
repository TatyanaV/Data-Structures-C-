void _dynArrSetCapacity(DynArr *v, int newCap)
{
    int i;
    TYPE *oldData;
    int oldSize = v->size;
    oldData = v->data;
    printf("========Resizing========\n");
    /* Create a new dyn array with larger underlying array */
    _initDynArr(v, newCap);
    for(i = 0; i < oldSize; i++)
    {
    v->data[i] = oldData[i];
    }
    v->size = oldSize;
    /* Remember, init did not free the original data */
    free(oldData);
    #ifdef ALTERNATIVE
    int i;
    /* Create a new underlying array*/
    TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
    assert(newData != 0);
    /* copy elements to it */
    for(i = 0; i < v->size; i++)
    {
    newData[i] = v->data[i];
    }
    /* Delete the oldunderlying array*/
    free(v->data);
    /* update capacity and size and data*/
    v->data = newData;
    v->capacity = newCap;
    #endif
}



oid _setCapacityDynArr(struct DynArr *v, int newCap) {
    //create a new array
    struct DynArr *new_v;
    assert(newCap > 0);
    new_v = malloc(newCap * sizeof(struct DynArr));
    assert(new_v != 0);
    initDynArr(new_v, newCap);

    //copy old values into the new array
    for (int i = 0; i < new_v->capacity; i++) {
        new_v->data[i] = v->data[i];
    }

    //free the old memory
    freeDynArr(v);

    //pointer is changed to reference the new array
    v = new_v;

}


void _setCapacityDynArr(struct DynArr *v, int newCap){
    // declare temp array and initalize
    TYPE *tempArr = malloc(sizeof(TYPE)*newCap);

    //copy the elements of v into temp
    int i;
    for(i = 0; i < v->size; ++i){
        tempArr[i] = v->data[i];
        segmentTime++;
    }

    // free old array
    free(v->data);
    assert(v != 0);

    //set v to address of temp
    v->data = tempArr;
    segmentTime++;

    v->capacity = newCap;
}
