let qwer = new Vue({
    el: '#songs',

    data: {
        songsSaved: [],
        nameFilterSaved: getUrlVars()["name"]
    },
    computed: {
        filteredSongs: function () {
            return this.songsSaved;
        }

    },
    methods: {
        searchSongs: function(e){
            event.preventDefault();
            this.fetchSongs();
        },
        fetchSongs: function () {
            console.log('fetchsongs');
            //console.log(this.nameFilterSaved);
            const name = this.nameFilterSaved;
            axios.get('/api/v1/search/0/', {
                params: {
                    name: name,
                },
                auth: {
                    username: getUsername(),
                    password: getPassword()
                }
                })
                .then(function (response) {
                    qwer.songsSaved = response.data.part;
                    if(response.data.pages > 1){
                        loadOtherSongs(response.data.pages);
                    }
                })
                .catch(function (error) {
                    console.log(error);
                });

             function loadOtherSongs(pages){
                for(let i = 1; i < pages; i++){
                    axios.get('/api/v1/search/' + i +'/', {
                        params: {
                            name:name
                        },
                        auth: {
                            username: getUsername(),
                            password: getPassword()
                        }
                    })
                        .then(function (response) {
                            //console.log(response)

                            //console.log('before concat');
                            //console.log(this.songsSaved);
                            qwer.songsSaved = qwer.songsSaved.concat( response.data.part);
                            //console.log(response);
                            //console.log('after concat');
                            //console.log(this.songsSaved);

                        })
                        .catch(function (error) {
                            console.log(error);
                        });
                }
            }



        },

        createSong: function (event) {
            event.preventDefault();
            //console.log(event);
            var formData = new FormData();
            formData.append("image", $('#image').prop('files')[0]);
            formData.append('name', $('#newSongName').val());
            formData.append('author', $('#author').val());
            formData.append('length', $('#length').val());
            formData.append('inform', $('#inform').val());


            let name = $('#newSongName').val();
            $('#newSongName').val('');
            $('#author').val('');
            $('#length').val(0);
            $('#inform').val('');


            axios.post('/api/v1/addSong', formData, {
                headers: {
                    'Content-Type': 'multipart/form-data'
                },
                auth: {
                    username: getUsername(),
                    password: getPassword()
                }
                })
                .then(function (response) {
                    console.log(response);
                    qwer.fetchSongs();
                     })
                .catch(function (error) {
                    console.log(error);
                });
        },
        removeSong: function (event) {
            var songId = event.target.attributes.song_id.value;
            console.log(songId);
            axios.delete('/api/v1/delete/' + songId, {
                auth: {
                    username: getUsername(),
                    password: getPassword()
                }
                    })
                .then(x => qwer.songsSaved.splice(qwer.songsSaved.findIndex(x => x.id === songId), 1)
                )
                .catch(function (error) {
                    console.log(error);
                });

        },

        mounted: function () {
            console.log('created');
            //qwer.nameFilterSaved = $('#searchHolder').value;
            //$('test').value = $('#searchHolder').value;

                this.fetchSongs();

        }
    },
});


function getUrlVars()
{
    var vars = [], hash;
    var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++)
    {
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
}

function getUsername(){
    return $("usernameHolder").value;
}
function getPassword(){
    return $("hashHolder").value;
}

