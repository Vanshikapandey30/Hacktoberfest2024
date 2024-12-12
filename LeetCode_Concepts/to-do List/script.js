let write = document.getElementById('write');
let todoList = document.getElementById('todo-list');
let todoForm = document.getElementById('todo-form');

todoForm.addEventListener('submit', function(event) {
    event.preventDefault();
    if (write.value.trim() !== '') {
        addList(write.value.trim());
        write.value = '';
    }
});

function addList(val) {
    let list = document.createElement('li');
    list.innerHTML = `${val}`;
    todoList.appendChild(list);

    list.addEventListener('click', function() {
        this.classList.toggle('done');
        if (this.classList.contains('done')) {
            this.style.backgroundColor = 'lightgreen';
        } else {
            this.style.backgroundColor = 'red'; 
        }
    });
}
