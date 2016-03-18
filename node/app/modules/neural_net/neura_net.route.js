(function() {

	'use strict';

    angular.module('medicamentosApp.cidade').config(Config);

    function Config($translateProvider, $urlRouterProvider, $stateProvider) {

        var cidadeSearch = {
            name: "cidadeSearch",
            url: "/cidade",
            controller: 'cidadeController',
            controllerAs: 'vm',
            templateUrl: "modules/cidade/neura_net.html"
        };
        var cidadeEdit = {
            abstract: true,
            name: "cidadeEdit",
            url: "/cidade/{id}",
            controller: 'cidadeEditController',
            controllerAs: 'vm',
            templateUrl: "modules/cidade/neura_net.edit.html"
        };
        var cidadeEditMain = {name: "cidadeEdit.main",
            url: "",
            controller: 'cidadeEditMainController',
            controllerAs: 'vm',
            templateUrl: "modules/cidade/neura_net.edit.main.html",
        };

        $stateProvider
            .state( cidadeSearch )
            .state( cidadeEdit )
            .state( cidadeEditMain )
        ;
    }


})();
