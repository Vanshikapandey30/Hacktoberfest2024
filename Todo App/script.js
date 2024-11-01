const tasks = [
	
];

const trashIcon =
	'<svg xmlns="http://www.w3.org/2000/svg" width="1em" height="1em" viewBox="0 0 256 256"><path fill="currentColor" d="M216 48h-40v-8a24 24 0 0 0-24-24h-48a24 24 0 0 0-24 24v8H40a8 8 0 0 0 0 16h8v144a16 16 0 0 0 16 16h128a16 16 0 0 0 16-16V64h8a8 8 0 0 0 0-16M96 40a8 8 0 0 1 8-8h48a8 8 0 0 1 8 8v8H96Zm96 168H64V64h128Zm-80-104v64a8 8 0 0 1-16 0v-64a8 8 0 0 1 16 0m48 0v64a8 8 0 0 1-16 0v-64a8 8 0 0 1 16 0"/></svg>';

const tasksContainer = document.getElementById("tasksContainer");
const taskForm = document.getElementById("taskForm");
const taskInput = document.getElementById("todoInput");

refresh();

function refresh() {
	tasksContainer.innerHTML = "";
	let tasksHtml = "";
	tasks.forEach((task) => {
		const taskHtml = `
            <div class="item ${task.done ? "item--done" : ""}" id="${task.id}">
                <div class="checkbox"></div>
                <p>${task.title}</p>
                <button>${trashIcon}</button>
            </div>
        `;
		tasksHtml += taskHtml;
	});
	tasksContainer.innerHTML = tasksHtml;
}

taskForm.addEventListener("submit", addItem);

tasksContainer.addEventListener("click", itemClick);

function addItem(e) {
	e.preventDefault();
	if (!taskInput.value) return;
	const task = {
		title: taskInput.value,
		done: false,
		id: Date.now() + ""
	};
	tasks.push(task);
	taskInput.value = "";
	refresh();
}

function itemClick(e) {
	const item = e.target.closest(".item");
	const deleteBtn = e.target.closest("button");
	if (!item) return;
	if (deleteBtn) deleteItem(item);
	else toggleItem(item);
}

function deleteItem(item) {
	const id = item.id;
	const index = tasks.findIndex((task) => task.id === id);
	tasks.splice(index, 1);
	refresh();
}

function toggleItem(item) {
	const done = item.classList.contains("item--done");
	console.log(done);
	const id = item.id;
	const index = tasks.findIndex((task) => task.id === id);
	tasks[index].done = !done;
	refresh();
}
