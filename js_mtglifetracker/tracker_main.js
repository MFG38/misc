life = 20;

function displayLife() {
	document.getElementById("trackerPlaceholder").innerText = life;
	setInterval(displayLife, 50);
}

function lifeUp () {
	life += 1;
}

function lifeDown() {
	life -= 1;
}

