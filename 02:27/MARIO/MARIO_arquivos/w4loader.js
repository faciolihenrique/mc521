var rcw4 = {
    base_url: "//recruitcoders.com",
    spinner_path: "/media/content/ajax-loader.gif",
    css_path: "/media/styles2/rcw4.css",
    callbacks: {},
};
rcw4.inject_css = function() {
    var css_link=document.createElement("link");
    css_link.setAttribute("rel", "stylesheet");
    css_link.setAttribute("type", "text/css");
    css_link.setAttribute("href", rcw4.base_url + rcw4.css_path);
    document.getElementsByTagName("head")[0].appendChild(css_link);
};
rcw4.callbacks.handle_a = function(){
	var widget = document.getElementById('rcv4_widget');
	var content = document.getElementById('rcv4_content');
	if(widget.className== 'open'){
		widget.className="";
		while (content.firstChild) {
			content.removeChild(content.firstChild);
		}
		
	} else {
		widget.className="open";
		
		var str = '';
		if(typeof window.rc_utm_source !== 'undefined'){
			str = '&utm_source=' + window.rc_utm_source;
		}
		
		var iframe=document.createElement("iframe");
		iframe.setAttribute('src', rcw4.base_url + '/widget4?utm_medium=widget4' + str);
		iframe.setAttribute('scrolling', 'no');
		content.appendChild(iframe);
		
	}
	return false;
}
rcw4.init = function(){
	var w=document.createElement("div");
	    w.setAttribute("id", "rcv4_widget");
	    w.innerHTML = "<a href=\"\" id=\"rcv4_handle_a\"><div id=\"rcv4_handle\"><span>Time for a new job?</span></div></a><div id=\"rcv4_content\"></div><div id=\"rcv4_footer\">Powered by <a href=\"http://recruitcoders.com\" target=\"_blank\">Recruit Coders</a>&trade;</div>"
	    document.getElementsByTagName("body")[0].appendChild(w);
	
	// <img src=\""+rcw4.base_url+rcw4.spinner_path+"\"/>
	
	this.inject_css();

	document.getElementById('rcv4_handle_a').onclick = this.callbacks.handle_a;
};
rcw4.init();
