int index;
if(ht == NULL){
    return;
}
ht->table = (hashLink**)malloc(sizeof(hashLink*) * tablesize);
ht->tablesize = size;
ht->count = 0;
for(index = 0; index < tablesize; index++){
    ht->table[index] =0;
}
