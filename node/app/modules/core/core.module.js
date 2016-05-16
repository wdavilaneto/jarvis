(function() {
    'use strict';

    angular.module('jarvisApp.core', [

        'http-auth-interceptor',

        /*
         * Angular modules
         */
        'ngAnimate',
        'ngCookies',
        'ngResource',
        'ngSanitize',
        'ngTouch',

        /*
         * AngularUI modules
         */
        'ui.bootstrap',
        //'ui.date',
        'ui.utils',
        'ui.select',
        'ui.grid',
        'ui.router',
        'blockUI',

        /*
         * 3rd Party modules
         */
        'toaster',
        'angucomplete-alt',
        'angularUtils.directives.dirPagination',
        'ngTagsInput',
        'pdf',
        'pascalprecht.translate',
        'angular-timeline',
        'xeditable',
        'dialogs.main',
        'ngFileUpload',
        'chart.js',
        'textAngular',

        /*
         * Commons app modules
         */
        'commons.directives',
        'commons.filters',
        'commons.controllers',
        'commons.services'
    ]);

})();