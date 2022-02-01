const djb2Hash = (data) => {

    var hash = 5381;
    const size = data.length
    var c;
    var i = 0;

    while(i < size){
        c = data.charAt(i).charCodeAt(0);
        hash = ((hash << 5) + hash) + c
        ++i;
    }
    return hash
}

