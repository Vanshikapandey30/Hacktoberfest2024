let adj = [];
let noOfVertices = 0;
let color = [];
let isBipartiteGraph = true;
const vertices = [];

function printGraph() {
    console.log("printing graph");
    for (var i = 0; i < noOfVertices; i++) {
        if (adj[i].length > 0)
            console.log("vertex " + (i + 1));
        for (var j = 0; j < adj[i].length; j++) {
            console.log(adj[i][j] + 1);
        }
    }
    return "done";
}

function addEdge(a, b) {
    if (noOfVertices == 0)
        return "first configure the no. of vertices in the graph";
    if (a > noOfVertices || b > noOfVertices || a < 1 || b < 1)
        return "vertices should be between 1 and " + noOfVertices;
    adj[a - 1].push(b - 1);
    adj[b - 1].push(a - 1);
    return `added edge between ${a} and ${b}`;
}

function setColorDefault() {
    isBipartiteGraph = true;
    for (let i = 0; i < color.length; i++)
        color[i] = 0;
}

function initializeGraph(noOfVertices) {
    adj = [];
    color = [];
    for (let i = 0; i < noOfVertices; i++)
        adj.push([]);

    for (let i = 0; i < noOfVertices; i++)
        color.push(0);

    return "initialized colors for vertices";
}

function defaultColor() {
    for (let i = 0; i < noOfVertices; i++)
        color[i] = 2;
}

function configureNoOfVertices(n) {
    noOfVertices = n;
    console.log(initializeGraph(noOfVertices));
    return "no. of vertices is configures to " + noOfVertices;
}

function DFS_ColorGraph(v) {
    if (isBipartiteGraph == false) {
        return false;
    }

    for (let u = 0; u < adj[v].length; u++) {
        if (color[adj[v][u]] == 0) {
            color[adj[v][u]] = 3 - color[v];
            DFS_ColorGraph(adj[v][u]);
        }
        if (color[adj[v][u]] == color[v]) {
            isBipartiteGraph = false;
            return false;
        }
    }
}

function checkBipartiteGraph() {
    let isBipartiteGraphOrNot = document.getElementById("isBipartiteGraphOrNot");
    for (let i = 0; i < noOfVertices; i++) {
        if (color[i] == 0 && isBipartiteGraph == true) {
            color[i] = (i > 0) ? 3 - color[i - 1] : 1;
            DFS_ColorGraph(i);
        }
    }

    if (isBipartiteGraph == false) {
        console.log("the given graph is not a bipartite graph");
        isBipartiteGraphOrNot.innerHTML = 'The given graph is not a bipartite graph';
        return true;
    }

    console.log("the given graph is a bipartite graph");
    isBipartiteGraphOrNot.innerHTML = 'The given graph is a bipartite graph';
    isBipartiteGraphOrNot.style.display = "block";
    return true;
}

function setNumberOfVertices() {
    let numOfVertices = document.getElementById("numOfVertices").value;
    let edge1 = document.getElementById("edge1");
    let edge2 = document.getElementById("edge2");
    document.getElementById("addEdge").style.display = (numOfVertices > 1) ? "block" : "none";
    document.getElementById("checkIfBipartite").style.display = "none";
    document.getElementById("isBipartiteGraphOrNot").style.display = "none";
    document.getElementById("checkIfBipartite").style.display = "block";
    document.getElementById("set-vertices").innerHTML = 'Reset';
    document.getElementById("graph-p").innerHTML = '';
    let graphContainer = document.getElementById('graph-container')
    configureNoOfVertices(numOfVertices);
    edge1.setAttribute('max', numOfVertices);
    edge2.setAttribute('max', numOfVertices);
    edge1.value = '';
    edge2.value = '';
    edge1.setAttribute("placeholder", `1-${numOfVertices}`);
    edge2.setAttribute("placeholder", `1-${numOfVertices}`);
    graphContainer.innerHTML = '<svg id="svg"></svg>';
    createGraph(numOfVertices);
}

let setNumberOfVerticesInput = document.getElementById("numOfVertices");
setNumberOfVerticesInput.addEventListener("keypress", function (event) {
    // If the user presses the "Enter" key on the keyboard
    if (event.key === "Enter") {
        // Cancel the default action, if needed
        event.preventDefault();
        // Trigger the button element with a click
        document.getElementById("set-vertices").click();
    }
});

function addEdgeToGraph() {
    let edge1 = document.getElementById("edge1").value;
    let edge2 = document.getElementById("edge2").value;
    if (edge1 == edge2)
        alert("edge to itself is not allowed");
    setColorDefault();
    createEdge(edge1, edge2);
    console.log(addEdge(edge1, edge2));
}

function createEdge(vertex1Name, vertex2Name) {
    const svg = document.getElementById('svg');
    const vertex1 = vertices.find(v => v.name == vertex1Name);
    const vertex2 = vertices.find(v => v.name == vertex2Name);

    if (!vertex1 || !vertex2) {
        console.error("One or both vertices not found");
        return;
    }

    // Create the edge (line)
    const edge = document.createElementNS("http://www.w3.org/2000/svg", "line");
    edge.setAttribute("x1", vertex1.x);
    edge.setAttribute("y1", vertex1.y);
    edge.setAttribute("x2", vertex2.x);
    edge.setAttribute("y2", vertex2.y);
    svg.appendChild(edge);
}

function createGraph(numVertices) {
    const container = document.getElementById('graph-container');
    // const numVertices = 10;
    let radius = numVertices * 20;  // Radius of the large circle
    container.style.width = (numVertices <= 3) ? '200px' : `${numVertices * 55}px`;
    container.style.height = (numVertices <= 3) ? '200px' : `${numVertices * 55}px`;
    const centerX = container.offsetWidth / 2;
    const centerY = container.offsetHeight / 2;

    for (let i = 0; i < numVertices; i++) {
        // Create vertex element
        const vertex = document.createElement('div');
        vertex.classList.add('vertex');
        const vertexName = `${i + 1}`;
        vertex.textContent = vertexName;

        // Calculate position of each vertex
        const angle = (2 * Math.PI / numVertices) * i;
        const x = centerX + radius * Math.cos(angle) - 20;  // Adjust for vertex size
        const y = centerY + radius * Math.sin(angle) - 20;

        // Set position of the vertex
        vertex.style.left = `${x}px`;
        vertex.style.top = `${y}px`;

        // Store the name and position of each vertex
        vertices.push({ name: vertexName, x: centerX + radius * Math.cos(angle), y: centerY + radius * Math.sin(angle) });

        // Add the vertex to the container
        container.appendChild(vertex);
    }
}