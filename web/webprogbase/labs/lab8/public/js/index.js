window.addEventListener('load', function () {




    let formEl = document.getElementById('searchForm');
    //load songs at start
    searchSongs(formEl);

    formEl.addEventListener('submit', function(e) {
        e.preventDefault();
        searchSongs(formEl);

    });

});

function getToken(){
    return document.getElementById("tokenHolder").value;
}

function searchSongs(form) {


    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (this.readyState === XMLHttpRequest.DONE) {
            if (this.readyState === 4 && this.status === 200) {
                //console.log(this.response);
                // albums = this.response.albums;
                // var source = document.getElementById('albums-template').innerHTML;
                // var template = Handlebars.compile(source);
                // var context = {
                //     albums: this.response.albums,
                //     user: JSON.parse(window.localStorage.getItem('user')),
                //     searchText: this.response.searchText
                // };
                // document.getElementById('albums').innerHTML = template(context)
                var template = document.getElementById("my-list-template").innerHTML;
                // згенерувати HTML строку на основі шаблону і даних
                var renderedHTML = Mustache.render(template, { songs: this.response.part });
                // помістити строку з HTML всередину елемента з ідентифікатором "my-list"
                document.getElementById("filteredSongs").innerHTML = renderedHTML;

                if(this.response.pages > 1){
                    loadOtherSongs(this.response.pages);
                    console.log('more than 1');
                }
            }
        }
    };
    function loadOtherSongs(pages){
        for(let i = 1; i < pages; i++){
            var ajax = new XMLHttpRequest();
            ajax.onreadystatechange = function () {
                if (this.readyState === XMLHttpRequest.DONE) {
                    if (this.readyState === 4 && this.status === 200) {
                        console.log(this.response);

                        var template = document.getElementById("my-list-template").innerHTML;
                        // згенерувати HTML строку на основі шаблону і даних
                        var renderedHTML = Mustache.render(template, { songs: this.response.part });
                        // помістити строку з HTML всередину елемента з ідентифікатором "my-list"
                        document.getElementById("songs-list").innerHTML += renderedHTML;

                    }
                }

            };
            console.log(form);
            ajax.open(form.method, form.action + i +'/?name=' + form.elements['name'].value, true);
            ajax.setRequestHeader('Authorization', getToken());
            ajax.responseType = 'json';
            ajax.send(new FormData(form))
        }
    }
    console.log(form);
    xhr.open(form.method, form.action + '0/?name=' + form.elements['name'].value, true);
    xhr.setRequestHeader('Authorization', getToken());
    xhr.responseType = 'json';
    xhr.send(new FormData(form))

}
