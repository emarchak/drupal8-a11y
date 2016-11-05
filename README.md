# Getting to know Drupal 8

## Accessibility Tools & Techniques

[@emarchak](http://twitter.com/emarchak)  | [emarchak.github.io/drupal8-a11y](http://emarchak.github.io/drupal8-a11y)
[text-only slides](http://emarchak.github.io/drupal8-a11y/presentation.html)

[Erin Marchak](http://myplanet.com)  
[@emarchak](http://twitter.com/emarchak)



[Myplanet](http://myplanet.com)

We build engaging web and mobile  
products for the enterprise

[@myplanetHQ](http://twitter.com/myplanetHQ)





## What am I going to cover?

1.  Why I'm here
2.  A11y & Drupal 8
3.  How to identify a11y gaps
4.  How to resolve a11y gaps
5.  Further resources







## Why I'm here

### A Case Study

# AMI





> Myplanet had a lot of empathy for what we were trying to do.  
> They felt and understood the mission we had for the site.

Virginia Vuleta  
_Director, Digital Strategy, Accessible Media Inc_


*   User Experience Testing
*   Design Audits
*   A11y Audits by [David MacDonald](http://www.davidmacd.com/)
*   Headless components using React.js


RuPaul in a large blonde wig, saying "put your money where your mug is.



## A11y & D8





### A11y 


> The power of the Web is  
> in its universality.

[Tim Berners-Lee](http://www.w3.org/standards/webdesign/accessibility)





#### Types of barriers

*   Physical, motor or mobile
*   Visual
*   Auditory
*   Learning
*   Speech or language
*   Mental, intellectual or developmental





#### Types of solutions

*   Keyboard, mouse & touch navigation
*   Screen readers compatibility & descriptive video
*   Captioning
*   Legible design & information architecture
*   Translatable content
*   Trigger warnings for content



![overcoming bad design](http://2.bp.blogspot.com/-itkFXKclo9o/UWfGAkP_1mI/AAAAAAAANa4/I7uPlyd1O9Y/s640/6.jpg)



#### [WCAG 2.0 Levels](http://www.w3.org/TR/WCAG20/)

1.  **Level A** - Essential
2.  **Level AA** - Preferred
3.  **Level AAA** - Optional (nice, but in-acheivable) 



### D8


[#D8AX - Drupal 8 Accessibility eXperience](https://www.drupal.org/about/features/accessibility)





#### A11y in Drupal 8

*   [WAI-ARIA](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-wai-aria), [HTML5 & Improved Semantics](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-html5-improved-semantics)
*   [Content authoring](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-alt-tags-defaults) & [ATAG Compliance](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-atag-compliance)
*   [Tab Control](https://www.drupal.org/node/1973218)
*   [Aural Alerts](https://www.drupal.org/node/1973218)
*   [Devel Accessibility](https://www.drupal.org/project/devel_a11y) module



[![How Drupal 8 Makes Your Website More Easily Accessible](img/gifford.png)](https://docs.google.com/presentation/d/19O3png9GsAam431zRd80EY3vDKMbXAnc4c0s2edpLa0/edit#slide=id.p6)

[How Drupal 8 Makes Your Website More Easily Accessible](https://docs.google.com/presentation/d/19O3png9GsAam431zRd80EY3vDKMbXAnc4c0s2edpLa0/edit#slide=id.p6)


Tyler, The Creator rapping the line "I think I'm wasting my damn time" from his music video Yonkers.


## We didn't want _technically accessible_, we wanted _beautifully accessible_



## How to identify a11y gaps





### Visual Testing

*   Plan heading structure early
*   Prioritize function over form
*   Allow indicators





### Automated Functional testing

*   Install the [Devel Accessibility](https://www.drupal.org/project/devel_a11y) module.
*   [WAVE toolbar by WebAIM](http://wave.webaim.org/report#/http://events.drupal.org/dublin2016)
*   [Tenon.io](https://tenon.io/index.php)





### Manual Functional testing

*   VoiceOver for macOS/iOS
*   TalkBack for Android
*   [NVDA](http://www.nvaccess.org/) for Windows
*   [JAWS](http://www.freedomscientific.com/Products/Blindness/JAWS) for Windows





### User Experience testing

*   Pairs of researchers meet with individual users
*   Examine behaviours & attitudes relevant to the workflow





<section data-state="orange-slide">



## How to resolve a11y gaps





### Functional solutions  
Code is available at [github.com/emarchak/drupal8-a11y](https://github.com/emarchak/drupal8-a11y)





#### Landmark Labels  
[Add descriptive aria labels to page landmarks.](https://github.com/emarchak/drupal8-a11y/commit/611ec51e9ab8eb27c539753ac9007092fce6cc65)

    <main aria-label="{{ 'Content'|t }}">





#### On-page scrolling  
[Animate the scrolling and handling of focus.](https://github.com/emarchak/drupal8-a11y/commit/611ec51e9ab8eb27c539753ac9007092fce6cc65)

    $('html, body')
      .animate({scrollTop: targetPosition.top}, 600)
      .promise()
      .then(function () {
        $(target).focus();
      });





#### Relate block titles & labels  
[Use aria labelled by on blocks to help with association.](https://github.com/emarchak/drupal8-a11y/commit/ecc243256ca49b0c3f2cb9c24c1381d32dcec0ba)

    <a
      id="{{ cta_id }}"
      class="btn btn-default"
      href="{{ content.field_call_to_action[0]['#url'] }}"
      aria-labelledby="{{ cta_id }} {{ heading_id }}">





#### Form Errors  
Enable Inline Form Errors module, & [remove HTML5 required attribute.](https://github.com/emarchak/drupal8-a11y/commit/eda820068fefb52f511f9936ed4a84908a3ed2fe)

    if (isset($variables['attributes']['required'])) {
      unset($variables['attributes']['required']);
    }





#### Aural Announcements  
[Use Drupal.announce to inform users when the UI has updated.](https://github.com/emarchak/drupal8-a11y/commit/1c7e5b5d5a9e4e4862df3500c60eec0fd7ac5715)

    Drupal.announce(updates, 'polite');

    Drupal.announce(updates, 'assertive');



#### Drupal Console CLI  

Use drupal console to speed up development!





### Experiential solutions





#### Visual Design Best Practices

*   Check early, check often
*   [Sketch Color Contrast Analyser](https://github.com/getflourish/Sketch-Color-Contrast-Analyser)
*   [WebAIM Accessibility Checklist](http://webaim.org/blog/accessibility-for-designers/)





#### UX Testing Best Practices

*   Mixing remote and in-person testing
*   Bring-your-own-device
*   Emphasis on depth over breadth



## Further Resources

*   The links contained in slide deck.
*   [Accessibility Myths Debunked: Why Smart Organizations Know it's Not Optional](https://www.youtube.com/watch?v=fUGu2FE1tjw)
*   [Fast Paced Drupal 8: Accelerating Development with Composer, Drupal Console, and Services](https://www.youtube.com/watch?v=D25VvNfT0J4)
*   [DrupalTO meetup group](http://www.meetup.com/drupalto/) for all your questions

RuPaul in a different large blonde wig, wagging her figner and saying "I don't want to hear any goddamn excuse"



# Thank you

[@emarchak](http://twitter.com/emarchak) / [@myplanetHQ](http://twitter.com/myplanetHQ)  
[emarchak.github.io/drupal8-a11y](http://emarchak.github.io/drupal8-a11y)
