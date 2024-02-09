document.addEventListener('DOMContentLoaded', function () {
    document.body.style.backgroundColor = "whitesmoke"
    const menuButton = document.getElementById('icon-button-menu');
    const offcanvas = document.getElementById('offcanvas');
    const closeButton = document.getElementById('close-button');
    const closeButton2 = document.getElementById('close-button2');
    const offcanvas2 = document.getElementById("offcanvas2");
    
    Add_Notification();

    menuButton.addEventListener('click', function () {
        console.log("click");
        offcanvas.style.left = '0px';
    });

    closeButton.addEventListener('click', function () {
        offcanvas.style.left = '-300px';
        //offcanvas2.style.right = '-300px';
    });

    window.addEventListener('click', function (event) {
        if (offcanvas.style.left === '0px' && !event.target.closest('.nav') && !event.target.closest('.offcanvas-menu') ) {
            offcanvas.style.left = '-300px';
        }
        if (offcanvas2.style.right === '0px' && !event.target.closest('.nav') && !event.target.closest('.offcanvas-menu2') ) {
            offcanvas2.style.right = '-400px';
        }

        
    });

    document.getElementById("icon-button-notification").addEventListener("click", function() {
        //var offcanvas = document.getElementById("offcanvas2");
        offcanvas2.style.right = 0+"px";
    });
    closeButton2.addEventListener('click', function () {
        //offcanvas.style.left = '-300px';
        offcanvas2.style.right = '-400px';
    });
    

    const cookiePopup = document.getElementById('cookie-popup');
    const acceptButton = document.getElementById('accept-cookie');
    const declineButton = document.getElementById('decline-cookie');

    // Check if cookie has been set
    if (!getCookie('cookieAccepted')) {
        cookiePopup.style.display = 'block';
    }

    // Add event listener to accept button
    acceptButton.addEventListener('click', function () {
        // Set cookie to expire in 30 days
        setCookie('cookieAccepted', true, 30);
        cookiePopup.style.display = 'none';
    });

    // Add event listener to decline button
    declineButton.addEventListener('click', function () {
        // Handle decline action (e.g., redirect to a different page)
        alert('You have declined to accept cookies.');
        cookiePopup.style.display = 'none';
    });


    window.addEventListener("scroll", () => {
        let scrollButton = document.querySelector(".up_btn");
        let scrollY = window.scrollY || document.documentElement.scrollTop;
    
        if (scrollY > 20) {
            scrollButton.style.opacity = 1;
        } else {
            scrollButton.style.opacity = 0;
        }
    });
    
    
});


function Add_Notification() {
    const card_note = document.querySelector("#news_in");
    fetch("news.json")
    .then(res => res.json())
    .then(news => {
        Array.from(news).forEach((e) => {
            console.log(e);
            const news_div = document.createElement("div");
            news_div.innerHTML = `
            <div class="card_notification">
            <div class="notification_content">
                <h2>${e.title}</h2>
                <p>${e.description}</p>
                <a href=${e.link}>Know More</a>
            </div>
            <div class="notification_image">
                <img src=${e.img} alt="Notification Image">
            </div>
            </div>
            `;
            card_note.appendChild(news_div);
        })
    })
}

// Function to set cookie
function setCookie(name, value, days) {
    const date = new Date();
    date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
    const expires = 'expires=' + date.toUTCString();
    document.cookie = name + '=' + value + ';' + expires + ';path=/';
}

// Function to get cookie
function getCookie(name) {
    const cookieName = name + '=';
    const decodedCookie = decodeURIComponent(document.cookie);
    const cookieArray = decodedCookie.split(';');
    for (let i = 0; i < cookieArray.length; i++) {
        let cookie = cookieArray[i];
        while (cookie.charAt(0) === ' ') {
            cookie = cookie.substring(1);
        }
        if (cookie.indexOf(cookieName) === 0) {
            return cookie.substring(cookieName.length, cookie.length);
        }
    }
    return '';
}