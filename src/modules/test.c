#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTNUM 10000

connect_info ci,cii;
binary_safe_string pub;

const char* tststrs[MAX_TESTNUM];
int current_index = 0;

void init()
{
    pub.length = 16;
    pub.str = (uint8_t *)"const_stringfuck";

    ci.server_ip[0]=cii.server_ip[0] = 54;
    ci.server_ip[1]=cii.server_ip[1] = 44;
    ci.server_ip[2]=cii.server_ip[2] = 64;
    ci.server_ip[3]=cii.server_ip[3] = 14;
    cii.server_port = ci.server_port = 321;
    cii.passphrase = ci.passphrase = pub;
    cii.connect_fd = ci.connect_fd = 123;
    bool tmpbool = false;
    binary_safe_string authbss = client_make_auth_query(&ci);
    binary_safe_string replybss = server_make_auth_reply(&cii,authbss,&tmpbool);
    client_deal_auth_reply(&ci,replybss);
}

bool test_endecode(const char *str, int len)
{
    binary_safe_string bs;
    bs.length = len;
    bs.str = (char *)malloc(bs.length);
    memcpy(bs.str, str, bs.length);

    client_query cq;
    cq.destination_ip[0] = 54;
    cq.destination_ip[1] = 44;
    cq.destination_ip[2] = 64;
    cq.destination_ip[3] = 14;
    
    cq.destination_port = 6543;
    cq.payload = bs;

    binary_safe_string ret = client_encode(&ci, cq);
    client_query decoded = server_decode(&cii, ret);
    //NO FREE
    return (strncmp(decoded.payload.str,str,len) == 0) && (len == decoded.payload.length);
}

void run_tests(){
    bool tstresults[MAX_TESTNUM];
    memset(tstresults,0,sizeof(tstresults));
    int successives = 0;
    for(int i=0;i<current_index;i++){
        // run tests
        bool result = test_endecode(tststrs[i],strlen(tststrs[i]));
        if(result) successives++;
        tstresults[i]=result;
    }
    printf("Test Passed: %d/%d\nFailed Tests are:",successives,current_index);
    for(int i=0;i<current_index;i++){
        if(!tstresults[i]) printf("%d: %s\n",i,tststrs[i]);
    }
    printf("\n");
}

#define TST(cstr) do{tststrs[current_index]=cstr;current_index++;}while(0);

int main()
{
    init();
    TST("ASDFSDFSDAFSDAFSADF")
    TST("aoing854ewg65e1gws5fg1aw2eg4fvawes325gfv4awsdefgv35sedfsd2454fgw2a4g")
    TST("")
    TST("65AEDFSG4ER35G4ER")
    TST("37984c5t32[34;.g5]5]23[45gv,p.423][  ???24654")
    TST("aoing854ewg65e1gws5fg1awasdf2eg4fvawes325gfv4awsdefgv35sedfsd2454fgw2a4g")
    TST("")
    TST("65AEDFSG4ERsdfew35G4ER")
    TST("37984c5t32[34;.g5]5]\x23 5gv,p.423][g  ???24654")
    TST(" (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function()")
    TST(" (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o)")
    TST(" m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m")
    TST(" })(window,document,'script','//www.google-analytics.com/analytics.js','ga')")
    TST(" ga('create', 'UA-4450461-3', 'branah.com')")
    TST(" ga('send', 'pageview')")
    TST("/script")
    TST("/head")
    TST("body")
    TST("   <div id=\"page\"")
    TST("       <div id=\"fb-root\"></div")
    TST("       <script")
    TST("           window.fbAsyncInit = function () ")
    TST("               FB.init(")
    TST("                   appId: '197832053577811'")
    TST("                   version: 'v2.1'")
    TST("                   channelUrl: '/channel'")
    TST("                   status: true")
    TST("                   cookie: true")
    TST("                   xfbml: false")
    TST("                   oauth: tru")
    TST("               })")
    TST("               FB.Event.subscribe('edge.create', function (targetUrl) ")
    TST("                   ga('send', 'social', 'facebook', 'like', targetUrl)")
    TST("               })")
    TST("               FB.Event.subscribe('edge.remove', function (targetUrl) ")
    TST("                   ga('send', 'social', 'facebook', 'unlike', targetUrl)")
    TST("               })")
    TST("               FB.Event.subscribe('message.send', function (targetUrl) ")
    TST("                   ga('send', 'social', 'facebook', 'send', targetUrl)")
    TST("               })")
    TST("           }")
    TST("           (function () ")
    TST("               var s = document.getElementById('fb-root')")
    TST("               var e = document.createElement('script')")
    TST("               e.src = 'https://connect.facebook.net/en_US/sdk.js'")
    TST("               e.async = true")
    TST("               s.appendChild(e)")
    TST("               document.getElementsByTagName(\"html\")[0].style.display = 'block'")
    TST("           }())")
    TST("       </script")
    TST("               <div id=\"header\"")
    TST("           <header")
    TST("               <a id=\"logo\" href=\"/\" title=\"Write in your language wherever you may be with the best online keyboard on the Internet\"></a")
    TST("           </header")
    TST("       </div")
    TST("       <div class=\"main_content\"")
    TST("           <div class=\"side_content\"")
    TST("               <script async src=\"https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js\"></script")
    TST("!-- Responsive --")
    TST("    data-ad-format=\"auto\"></ins")
    TST("script")
    TST("adsbygoogle = window.adsbygoogle || []).push({})")
    TST("/script")
    TST("           </div")
    TST("           <h1>ASCII Converter - Hex, decimal, binary, base64, and ASCII converter</h1")
    TST("           <p><input type=\"button\" id=\"btnascii\" value=\"Convert\" style=\"width:100px\"> ASCII (Example: a b c)<br")
    TST("textarea id=\"ascii\" rows=\"4\" cols=\"75\"></textarea><br><input type=\"button\" id=\"separate\" value=\"Add spaces\" style=\"width:100px\"><input type=\"button\" id=\"combine\" value=\"Remove spaces\" style=\"margin-left:1em;width:100px\"><label style=\"margin-left:1em\"><input type=\"checkbox\" id=\"whitespace\"> Convert white space characters</label></p")
    TST("p><input type=\"button\" id=\"btnhex\" value=\"Convert\" style=\"width:100px\"> Hex (Example: 0x61 0x62 0x63) <label style=\"margin-left:1em\"><input type=\"checkbox\" id=\"zerox\"> Remove 0x</label><br")
    TST("textarea id=\"hex\" rows=\"4\" cols=\"75\"></textarea></p")
    TST("p><input type=\"button\" id=\"btndec\" value=\"Convert\" style=\"width:100px\"> Decimal (Example: 97 98 99)<br")
    TST("textarea id=\"dec\" rows=\"4\" cols=\"75\"></textarea></p")
    TST("p><input type=\"button\" id=\"btnbinary\" value=\"Convert\" style=\"width:100px\"> Binary (Example: 01100001 01100010 01100011)<br")
    TST("textarea id=\"binary\" rows=\"4\" cols=\"75\"></textarea></p")
    TST("p><input type=\"button\" id=\"btnbase64\" value=\"Convert\" style=\"width:100px\"> Base64 (Example: YSBiIGM=)<br")
    TST("textarea id=\"base64\" rows=\"4\" cols=\"75\"></textarea></p")
    TST("           <div id=\"share\"><a id=\"share-buttons\" href=\"#\">Share</a><div id=\"fshare\" class=\"share\"><div class=\"fb-like\" data-href=\"https://www.branah.com/ascii-converter\" data-layout=\"button_count\" data-action=\"like\" data-share=\"true\" data-show-faces=\"false\" data-colorscheme=\"light\"></div></div><div id=\"tshare\" class=\"share\"><a href=\"https://www.branah.com/ascii-converter\" class=\"twitter-share-button\" data-size=\"medium\"></a></div><div id=\"gshare\" class=\"share\"><div class=\"g-plusone\" data-href=\"https://www.branah.com/ascii-converter\"  data-annotation=\"bubble\" data-size=\"medium\"></div></div><div class=\"clear\"></div></div")
    TST("           <p><em>ASCII Converter</em> enables you to easily convert ASCII characters to their hex, decimal, and binary representations. In addition, base64 encode/decode binary data. As you type in one of the text boxes above, the other boxes are converted on the fly.</p")
    TST("p>The ASCII converter doesn't automatically add spaces between the converted values. You can use the add spaces button to separate the ASCII characters so that the converted values will also be separated from one another.</p")
    TST("p>White space characters are not converted unless the white space check box is checked.</p")
    TST("p>When converting hex to ASCII, use two digit hex values. For four digit hex values, you may find the <a href=\"./unicode-converter\">Unicode Converter</a> useful.</p")
    TST("          ")
    TST("           <p><script async src=\"https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js\"></script")
    TST("!-- Responsive --")
    TST("           <div id=\"archived\">View archived comments <a href=\"/comments?r=ascii-converter\">here</a></div")
    TST("           <div id=\"comments\"><a id=\"fcomments\" href=\"#\">Load Comments</a><fb:comments href=\"https://www.branah.com/ascii-converter\" num_posts=\"10\" width=\"625\"></fb:comments")
    TST("           </div")
    TST("          ")
    TST("       </div")
    TST("       <div id=\"footer\"")
    TST("           <footer")
    TST("               <ul class=\"menu\"")
    TST("                   <li class=\"menuitem\"><a href=\"/\" title=\"Home\">Home</a></li")
    TST("                   <li class=\"menuitem\"><a href=\"/help\" title=\"Help\">Help</a></li")
    TST("                   <li class=\"menuitem\"><a href=\"/contact\" title=\"Contact\">Contact</a></li")
    TST("                   <li class=\"menuitem\"><a href=\"/terms-of-use\" title=\"Terms of use\">Terms of Use</a></li")
    TST("                   <li class=\"menuitem\"><a href=\"/privacy-policy\" title=\"Privacy policy\">Privacy Policy</a></li")
    TST("                   <li class=\"menuitem\">© branah.com</li")
    TST("               </ul")
    TST("           </footer")
    TST("       </div")
    TST("   </div")
    run_tests();
}