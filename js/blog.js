/*!
 * Clean Blog v1.0.0 (http://startbootstrap.com)
 * Copyright 2015 Start Bootstrap
 * Licensed under Apache 2.0 (https://github.com/IronSummitMedia/startbootstrap/blob/gh-pages/LICENSE)
 */

// Tooltip Init
$(function() {
    $("[data-toggle='tooltip']").tooltip();
});


// make all images responsive
/*
 * Unuse by Hux
 * actually only Portfolio-Pages can't use it and only post-img need it.
 * so I modify the _layout/post and CSS to make post-img responsive!
 */
// $(function() {
//  $("img").addClass("img-responsive");
// });

// responsive tables
$(document).ready(function() {
    $("table").wrap("<div class='table-responsive'></div>");
    $("table").addClass("table");
});

// responsive embed videos
$(document).ready(function () {
    $('iframe[src*="youtube.com"]').wrap('<div class="embed-responsive embed-responsive-16by9"></div>');
    $('iframe[src*="youtube.com"]').addClass('embed-responsive-item');
    $('iframe[src*="vimeo.com"]').wrap('<div class="embed-responsive embed-responsive-16by9"></div>');
    $('iframe[src*="vimeo.com"]').addClass('embed-responsive-item');
});

// 判断是不是博文页面
function isPages(attr){
    var currentBoolean = document.querySelector('.navbar.navbar-custom').getAttribute(attr);
    if(currentBoolean === 'true'){return true;}
    return false;
}
/*
    滚动函数
    接收三个参数,
        1 接收一个DOM对象
        2 给目标对象切换class
        3 触发的高度 (可选项,如果不指定高度,会将DOM的高度作为触发高度)
*/
function scrollCheck(scrollTarget, toggleClass, scrollHeight){
    document.addEventListener('scroll',function(){
    var currentTop = window.pageYOffset;
        currentTop > (scrollHeight||scrollTarget.clientHeight)
        ?scrollTarget.classList.add(toggleClass)
        :scrollTarget.classList.remove(toggleClass)
    })
}

//主页
(function(){
    if(!isPages('data-ispost')){
        var navbar = document.querySelector('.navbar.navbar-custom')
        navbar.classList.add('is-fixed');
    }

})();

/*
* 先获取H1标签
* 然后滚动出现固定导航条后
* 将其内容放到上面居中显示
* */

/*
    博文页面
*/
(function(){
    if (isPages('data-ispost')){
        var navbar = document.querySelector('.navbar-custom');
        var introHeader = document.querySelector('.intro-header').offsetHeight;
        var introHeader = introHeader > 497 ? introHeader : 400;
        var toc = document.querySelector('.toc-wrap');
        var postTitle = document.querySelector('.post-title-haojen');
        scrollCheck(toc,'toc-fixed',introHeader-60);
        scrollCheck(navbar,'is-fixed');
        scrollCheck(postTitle,'post-title-fixed',introHeader-60);
    }
})();

(function () {
    var navTop = document.querySelector('#nav-top');
    navTop.ondblclick = function () {
        $('body').animate({
            scrollTop: 0
        }, 500)
    }
})();

var codeItem = document.getElementsByClassName('code');
/*
	添加代码复制按钮
*/
(function(){
	for(var i = 0; i < codeItem.length; i++)
	{
		var copyButton = document.createElement("button");
		copyButton.innerHTML = 'Copy';
		copyButton.setAttribute("onclick", `copyCode(${i})`);
		var copyText = document.createElement("textarea");
		copyText.setAttribute("readonly", "readonly");
		copyText.value = codeItem[i].lastChild.innerText;
		// copyText.setAttribute("style", "display: contents");
		copyText.style["display"] = "contents";
		var rows = Number(codeItem[i].firstChild.childElementCount / 2);
		copyText.setAttribute("rows", `${rows}`);
		var div = document.createElement("div");
		div.setAttribute("class", "copy");
		div.appendChild(copyText);
		div.appendChild(copyButton);
		codeItem[i].insertBefore(div, codeItem[i].firstChild);
	}
})();

function copyCode(i)
{
    if(i < 0 || i >= codeItem.length)
		return;
	codeItem[i].lastElementChild.style['display'] = 'none';
	codeItem[i].firstChild.lastElementChild.style['display'] = 'none';
	var codeView = codeItem[i].firstChild.firstElementChild;
	codeView.style["display"] = "";
	codeView.select();
	try{
		if(document.execCommand('copy', false, null)){
			//success info  成功了放些提示
			console.log("复制成功");
			codeView.style["display"] = "none";
			codeItem[i].lastElementChild.style['display'] = '';
			codeItem[i].firstChild.lastElementChild.style['display'] = '';
			return;
		} else{
			//fail info   失败了放些提示
			console.log("复制失败");
		}
	} catch(err){
		//fail info 失败了放些提示
		window.prompt("复制失败了，请手动复制此内容: " + err, url); 
		console.log("手动复制");
	}
}