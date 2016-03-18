(function() {
   'use strict';

	angular.module('jarvisApp').config(Config);

    function Config($translateProvider, $urlRouterProvider, $stateProvider) {

        $stateProvider
            .state('main', {
                url: "/",
                controller: 'MainController',
                controllerAs: 'mainController',
                templateUrl: "modules/main/main.html"
            })
        ;

        $urlRouterProvider.otherwise("/");
        $translateProvider.useStaticFilesLoader({prefix: '/', suffix: '.json'});
        $translateProvider.preferredLanguage('i18n/locale-pt-BR');

    }

})();